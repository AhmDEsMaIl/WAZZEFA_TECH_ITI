import sys
import subprocess
from time import sleep


def get_file_size(file_object):
    """Gets the size of a file object in kilobytes."""
    file_object.seek(0, 2)  # Seek to the end of the file
    size = file_object.tell()
    return size / 1024  # Convert bytes to kilobytes


def convert_exe_to_hex(target_file):
    """Converts an EXE file to an array of hex using PowerShell."""
    try:
        command = f"[byte[]] $hexdump = Get-Content -Encoding Byte -Path '{target_file}'; [System.IO.File]::WriteAllLines('hex-payload.txt', ([string]$hexdump))"
        output = subprocess.check_output(['powershell', '-noprofile', '-command', command])
        print("Now!! Converting....")
        print("Successful converting.... | Payloaded in 'hex-payload.txt'")
        sleep(3)

        with open("hex-payload.txt", 'rb') as file:
            payload_size = get_file_size(file)
            print(f"Payload size: {payload_size:.2f} KB")
            print("Let's check your Payload")
    except Exception as e:
        print(f"Error: {e}")


if __name__ == "__main__":
    if len(sys.argv) == 2:
        convert_exe_to_hex(sys.argv[1])
    else:
        print("Usage: python exe-transformex.py <.EXE file>")


print('''
#################################################################################
#  Simple Python (and PowerShell) script for converting EXE files to Array of HEX  #
# By un4ckn0wl3z | https://haxtivitiez.wordpress.com                             #
#################################################################################
''')


