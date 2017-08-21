import os
import time

empty_file = set()
cpp_file = set()

def count():
    cnt = 0
    for root,dirs,files in os.walk(".."):
        for f in files:
            if (f == 'main.cpp'):
                path = os.path.join(root,f)
                tmp = parse(path)
                if tmp > 10:
                    cpp_file.add(path)
                    cnt += tmp
                else:
                    empty_file.add(path)
    return cnt

def parse(path):
    cnt = 0
    with open(path) as fp:
        for line in fp:
            if len(line.strip()) > 0: cnt += 1
    return cnt


if __name__ == "__main__":
    lines = count()
    print("There are %d cpp files." %len(cpp_file))
    print("There are %d lines of cpp code." %lines)
    print("There are %d empty files." %len(empty_file))
    for path in empty_file:
        print(path)
    t = time.time()
    t = time.localtime(t)
    t = time.asctime(t)

    with open("records.md", 'a') as fp:
        s = ''
        if fp.tell() != 0:
            s += "***\n"
        s += "### " + t + '\n'
        s += "* CPP files: %d (+%d)\n" %(len(cpp_file), len(empty_file))
        s += "* Lines: %d\n" %lines
        fp.write(s)