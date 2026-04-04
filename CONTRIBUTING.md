
# Contributing to Heart Rate Monitor

Thank you for your interest in contributing! This guide will help you get started.

## Code of Conduct
- Be respectful to all contributors
- Provide constructive feedback
- Help others learn and grow
- Report issues responsibly

## How to Contribute

### 1. Report Issues
Found a bug? Have a suggestion?

**Create an Issue:**
1. Go to Issues tab
2. Click "New Issue"
3. Provide:
   - Clear title
   - Description of problem
   - Steps to reproduce
   - Your environment (OS, Arduino IDE version)

**Good Issue Example:**
Title: MAX30100 not initializing on startup

Description: When I upload the code, the sensor initialization fails. I've verified the connections are correct.

Steps:

Upload heart-rate-monitor.ino
Open Serial Monitor
See "FAILED to initialize MAX30100"
Environment:

Windows 10
Arduino IDE 1.8.19
ESP32 Board Support 2.0.5
MAX30100 genuine sensor
Code

### 2. Submit Pull Requests

**For bug fixes:**
1. Fork the repository
2. Create branch: `git checkout -b fix/bug-name`
3. Make changes
4. Test thoroughly
5. Commit with clear message: `git commit -m "Fix: brief description"`
6. Push: `git push origin fix/bug-name`
7. Create Pull Request on GitHub

**For features:**
1. Discuss in Issues first
2. Fork and create: `git checkout -b feature/feature-name`
3. Add code AND documentation
4. Add examples if applicable
5. Submit PR with description

**Good PR Description:**
What
Added data logging to SD card

Why
Users want to save readings for analysis

How
Reads MAX30100 data
Saves to data.csv every second
Uses SD library for I/O
Testing
Tested on ESP32 with 16GB SD card
Verified 1000+ readings
No data corruption
Checklist
 Code follows style guide
 Comments added
 Documentation updated
 No new warnings
Code

### 3. Improve Documentation
- Fix typos
- Add examples
- Improve guides
- Add translations

### 4. Code Contributions

**Code Style:**
```cpp
// Clear comments
// Proper variable names (not x, y, z)
// Consistent indentation (2 spaces)
// Functions with documentation

void sensorRead() {  // Good: clear name
  // Read and process data
}

void sr() {  // Bad: unclear name
  // ...
}
What we accept:

Bug fixes
Performance improvements
New features (discussed first)
Documentation improvements
Examples and tutorials
What we may decline:

Major rewrites without discussion
Undocumented code
Code without comments
Changes without testing
Development Setup
Clone and Setup
bash
git clone https://github.com/Master-QAT/Heart-Rate-Monitor.git
cd Heart-Rate-Monitor
Test Your Changes
Compile in Arduino IDE (Verify button)
Upload to real ESP32
Test all features
Check Serial Monitor for errors
Commit Message Format
Code
Type: Brief description

Detailed explanation if needed.

- Bullet points for changes
- Fix any related issues (#123)
Types:

Fix: Bug fixes
Feature: New features
Docs: Documentation
Refactor: Code reorganization
Test: Testing improvements
Project Structure
Code
Heart-Rate-Monitor/
├── src/                 # Source code
│   ├── heart-rate-monitor/
│   └── MAX30100/
├── docs/               # Documentation
├── hardware/           # Circuit diagrams
├── examples/           # Example code
└── tests/              # Tests (future)
Documentation Standards
README Quality
Clear project description
Installation instructions
Quick start guide
Troubleshooting section
Code Comments
Explain WHY, not WHAT
One sentence comments above code blocks
Function documentation with parameters
Examples
Work without modification
Include comments
Show practical use cases
Questions?
Check existing Issues
Comment on related discussions
Ask in Pull Request
Credit
Contributors will be listed in:

CONTRIBUTORS.md (created soon)
Project releases
GitHub contributors page
Thank you for making this project better!

Master-QAT

Code
