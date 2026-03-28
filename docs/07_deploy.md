# Deployment Guide

## Requirements
- g++ compiler
- Linux/macOS/Windows environment

## Steps

1. Clone repository:
   git clone <repo_url>

2. Navigate to project:
   cd project_folder

3. Compile:
   g++ -Iinclude src/twosum.cpp tests/test_twosum.cpp -o test

4. Run:
   ./test

## Notes
- Ensure g++ is installed
- CI pipeline can automate this process