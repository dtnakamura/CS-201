import sys
import os
import time

def main():
    outfile = open("test10.csv","w")
    outfile.write("Descending:,\n")
    for i in range(0, 100):
        #print("Number ", i, " of 100")
        tStart = time.time()
        os.system("./heapsort -d integers10")
        tStop = time.time()
        outfile.write(str(tStop-tStart))
        outfile.write(",")
    outfile.write("\nAscending:,\n")
    for i in range(0,100):
        #print("Number ", i, " of 100")
        tStart = time.time()
        os.system("./heapsort integers10")
        tStop = time.time()
        outfile.write(str(tStop - tStart))
        outfile.write(",")
    outfile.close()
    print("Done with 10, moving on to 100...")

    outfile = open("test100.csv","w")
    outfile.write("Descending:,\n")
    for i in range(0, 100):
        #print("Number ", i, " of 100")
        tStart = time.time()
        os.system("./heapsort -d integers100")
        tStop = time.time()
        outfile.write(str(tStop-tStart))
        outfile.write(",")
    outfile.write("\nAscending:,\n")
    for i in range(0,100):
        #print("Number ", i, " of 100")
        tStart = time.time()
        os.system("./heapsort integers100")
        tStop = time.time()
        outfile.write(str(tStop - tStart))
        outfile.write(",")
    outfile.close()
    print("Done with 100, moving on to 1k...")

    outfile = open("test1000.csv","w")
    outfile.write("Descending:,\n")
    for i in range(0, 100):
        #print("Number ", i, " of 100")
        tStart = time.time()
        os.system("./heapsort -d integers1000")
        tStop = time.time()
        outfile.write(str(tStop-tStart))
        outfile.write(",")
    outfile.write("\nAscending:,\n")
    for i in range(0,100):
        #print("Number ", i, " of 100")
        tStart = time.time()
        os.system("./heapsort integers1000")
        tStop = time.time()
        outfile.write(str(tStop - tStart))
        outfile.write(",")
    outfile.close()
    print("Done with 1k, moving on to 10k...")

    outfile = open("test10000.csv","w")
    outfile.write("Descending:,\n")
    for i in range(0, 100):
        #print("Number ", i, " of 100")
        tStart = time.time()
        os.system("./heapsort -d integers10000")
        tStop = time.time()
        outfile.write(str(tStop-tStart))
        outfile.write(",")
    outfile.write("\nAscending:,\n")
    for i in range(0,100):
        #print("Number ", i, " of 100")
        tStart = time.time()
        os.system("./heapsort integers10000")
        tStop = time.time()
        outfile.write(str(tStop - tStart))
        outfile.write(",")
    outfile.close()
    print("Done with 10k, moving on to 100k...")

    outfile = open("test100000.csv","w")
    outfile.write("Descending:,\n")
    for i in range(0, 100):
        #print("Number ", i, " of 100")
        tStart = time.time()
        os.system("./heapsort -d integers100000")
        tStop = time.time()
        outfile.write(str(tStop-tStart))
        outfile.write(",")
    outfile.write("\nAscending:,\n")
    for i in range(0,100):
        #print("Number ", i, " of 100")
        tStart = time.time()
        os.system("./heapsort integers100000")
        tStop = time.time()
        outfile.write(str(tStop - tStart))
        outfile.write(",")
    outfile.close()
    print("Done with 100k, moving on to 1M...")

    outfile = open("test1000000.csv","w")
    outfile.write("Descending:,\n")
    for i in range(0, 100):
        #print("Number ", i, " of 100")
        tStart = time.time()
        os.system("./heapsort -d integers1000000")
        tStop = time.time()
        outfile.write(str(tStop-tStart))
        outfile.write(",")
    outfile.write("\nAscending:,\n")
    for i in range(0,100):
        #print("Number ", i, " of 100")
        tStart = time.time()
        os.system("./heapsort integers1000000")
        tStop = time.time()
        outfile.write(str(tStop - tStart))
        outfile.write(",")
    outfile.close()
    print("All done!!!")
main()