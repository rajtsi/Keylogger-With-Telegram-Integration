# Keylogger-With-Telegram-Integration

# Keylogger with Telegram Integration

This is a simple keylogger program with Telegram integration. It captures keystrokes entered by the user and sends the logged data to a specified Telegram chat using the Telegram Bot API.

## Features

- Captures keystrokes from the keyboard
- Logs the captured keystrokes in a local file
- Sends the logged data to a specified Telegram chat using the Telegram Bot API

## Installation

1. Clone the repository or download the source code.
2. Ensure you have the necessary dependencies installed:
   - Install the libcurl library: https://curl.se/libcurl/
   - Install the cpr library: https://github.com/whoshuu/cpr
   - Set up a Telegram bot and obtain the Bot API token: https://core.telegram.org/bots#creating-a-new-bot
3. Replace the placeholders in the code:
   - Replace `YOUR_TELEGRAM_BOT_API_TOKEN` with your actual Telegram Bot API token.
   - Replace `YOUR_CHAT_ID` with the appropriate Telegram chat ID where you want to send the log messages.
4. Compile and build the code using your preferred C++ compiler.

## Usage

1. Run the compiled executable.
2. The keylogger will start running in the background and capturing keystrokes.
3. The captured keystrokes will be logged in a file named `Record.txt`.
4. At the specified frequency (in minutes), the keylogger will send the logged data to the specified Telegram chat using the Telegram Bot API.

## Security and Privacy

- Ensure that you have the necessary permissions and legal rights to use a keylogger.
- Use this program responsibly and adhere to applicable laws and regulations.
- Do not use this program for malicious purposes or to invade someone's privacy.
- Take appropriate measures to protect the generated log files and the data they contain.

## Disclaimer

This program is provided for educational and informational purposes only. The authors of this program are not responsible for any misuse or illegal activities conducted using this software. Use it at your own risk.


