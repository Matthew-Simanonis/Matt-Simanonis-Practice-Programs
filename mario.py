from cs50 import get_int
import sys

def main():
    print("How tall is the pyramid?")
    height = get_positive_int()
    draw(height)


def get_positive_int():
    while True:
        n = get_int("")
        if n < 9 and n > 0:         # Value must remain within 1 and 8
            break
        else:
            print("Value out of range")
    return n



def draw(h):
    for i in range(h):
        j = h - i - 1
        print(" " * j + "#" * (i + 1)+ "  "+ "#" * (i+1))







main()