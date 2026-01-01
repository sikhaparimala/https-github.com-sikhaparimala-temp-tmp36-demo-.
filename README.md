Don’t paste just the title — paste the whole README content. Copy everything below and paste it into the editor area.

Filename (top box): README.md

Paste this exact text into the editor:

# TMP36 → 16x2 LCD + Serial (Tinkercad demo)

This repo contains:
- `temperature_sensor.ino` — Arduino sketch (TMP36) that prints temperature to a 16x2 LCD and Serial Monitor.
- `demo_script.txt` — short script for a ~60s demo video (add later if needed).

How to run in Tinkercad:
1. Open https://www.tinkercad.com/ → Circuits → Create new Circuit.
2. Add: Arduino Uno, Temperature Sensor (TMP36), LCD 16x2, 10k pot.
3. Wire TMP36 (flat face toward you): left -> 5V, middle -> A0, right -> GND.
4. Wire LCD to match pins in `temperature_sensor.ino` (RS=D12, E=D11, D4=D5, D5=D4, D6=D3, D7=D2).
5. In the Tinkercad code editor choose Text, paste `temperature_sensor.ino`, Save, Start Simulation.
6. Open Serial Monitor and move the TMP36 slider — the LCD and Serial Monitor will update.

Deliverables to include:
- Demo video (MP4) showing wiring, code editor, start simulation, and the TMP36 slider updating LCD & Serial.
- `serial_log.txt` (copy from Tinkercad Serial Monitor).
- Screenshots: circuit wiring and LCD/Serial output.

