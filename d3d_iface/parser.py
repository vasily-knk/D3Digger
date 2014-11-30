import re


def make_regex():
    title = "(MIDL_INTERFACE"
    before = "[^{]*"
    open = "{"
    body = "[^{}]*"
    close = "};)"

    return re.compile(title + before + open + body + close)


if __name__ == "__main__":
    regex = make_regex()

    records = []
    with open("d3d10.h") as f:
        str = f.read()

        it = re.finditer(regex, str)
        for m in it:
            records.append(m.group(1))

    with open("dst.h", "w") as f:
        for r in records:
            f.write(r)
            f.write('\n')
