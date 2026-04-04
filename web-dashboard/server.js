const express = require('express');
const http = require('http');
const WebSocket = require('ws');
const path = require('path');

const app = express();
const server = http.createServer(app);
const wss = new WebSocket.Server({ server });

// Serve static files
app.use(express.static('public'));

// Simulate sensor data
let heartRate = 75;
let spo2 = 98;
let isAbnormal = false;

// Simulate realistic sensor variations
setInterval(() => {
    // Random small variations
    heartRate += (Math.random() - 0.5) * 4;  // ±2 variation
    spo2 += (Math.random() - 0.5) * 1;       // ±0.5 variation

    // Keep in realistic ranges
    heartRate = Math.max(50, Math.min(130, Math.round(heartRate)));
    spo2 = Math.max(85, Math.min(100, Math.round(spo2)));

    // Determine if abnormal
    isAbnormal = heartRate < 60 || heartRate > 110 || spo2 < 90;

    // Send to all connected clients
    wss.clients.forEach((client) => {
        if (client.readyState === WebSocket.OPEN) {
            client.send(JSON.stringify({
                hr: heartRate,
                spo2: spo2,
                timestamp: new Date().toLocaleTimeString(),
                abnormal: isAbnormal
            }));
        }
    });
}, 1000);  // Update every second

wss.on('connection', (ws) => {
    console.log('📱 Client connected');
    ws.send(JSON.stringify({ message: 'Connected to Heart Rate Monitor Dashboard' }));
});

wss.on('close', () => {
    console.log('📱 Client disconnected');
});

const PORT = 3000;
server.listen(PORT, () => {
    console.log(`\n✅ Dashboard running at http://localhost:${PORT}`);
    console.log('📊 Simulating realistic heart rate and SpO2 data\n');
});