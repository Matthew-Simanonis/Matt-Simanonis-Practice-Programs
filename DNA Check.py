import sys
import csv

def main():
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")         # Check for Command line (CSV file, Txt File)
        exit(1)

    with open(sys.argv[1], newline = '') as csvfile:        # Open CSV
        nomatch = True
        database = csv.DictReader(csvfile)
        header = database.fieldnames            # Create headers array
        for row in database:
            for i in range(1, len(header)):     # For each header
                match = True
                sequence = header[i]
                seqlength = len(sequence)       # Get length of header
                txt = open(sys.argv[2], "r")        # Open txt
                dna = txt.readline()                # Read txt
                seqcount = 0                    # Reset counters
                maxseq = 0
                for char in range(len(dna)):                    # For each character in DNA text
                    s = dna[char:char+seqlength]                # Scan string w/ length of sequence
                    while dnacheck(s, sequence) == True:        # Check string vs sequence
                        seqcount += 1
                        char += seqlength                   # If match, add 1 count, skip to next string
                        s = dna[char:char+seqlength]
                    if  seqcount > maxseq:
                        maxseq = seqcount
                    seqcount = 0

                if maxseq != int(row[sequence]):        # If not a match, move to next header
                    match = False                       # Set match to False
                    break
            if match == True:
                print(row['name'])
                nomatch = False
        if nomatch == True:
            print("No Match")

def dnacheck(string, sequence):         # DNA check function (String, String)
    if string == sequence:              # Check string against sequence
        return True
    else:
        return False

main()
