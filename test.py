# Create a Python script to print a 64-bit binary number with spaces every 8th digit
def format_binary(num):
    # Get the 64-bit binary representation
    binary_str = format(num, '064b')

    # Split into groups of 8 bits
    formatted_binary = ' '.join(binary_str[i:i+8] for i in range(0, len(binary_str), 8))
    
    return formatted_binary

# Take an integer as input
num = 512

# Format the number and print it
print(format_binary(num))
