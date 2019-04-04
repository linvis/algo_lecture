#!/usr/bin/env python
# -*- coding=utf8 -*-

def search(pattern, text):
    # use pattern[0] may outof range
    if pattern.startswith('^'):
        return match(pattern[1], text)
    else:
        return match(".*" + pattern, text)

def match(pattern, text):
    if pattern == '':
        return True
    elif pattern == '$':
        return (text == '')
    elif len(pattern) > 1 and pattern[1] in "*?":
        p, op, pat = pattern[0], pattern[1], pattern[2:]
        if op == "*":
            return match_star(p, pat, text)
        elif op == '?':
            if match1(p, text) and match(pat, text[1:]):
                return True
            else:
                return match(pat, text)

    else:
        return match1(pattern[0], text) \
               and match(pattern[1:], text[1:])

def match1(p, text):
    if not text: return False;
    return p == '.' or p == text[0]

# wrong logic, match_star will judge match1 first
# if match1(p, text):
#     return match_star(p, pattern, text[1:])
# else:
#     return match(pattern, text)
def match_star(p, pattern, text):
    # return (match(pattern, text) or (match1(p, text) and match_star(p, pattern, text[1:])))


def test():
    assert search('baa*!', 'Sheep said baaaa!')
    assert search('baa*!', 'Sheep said baaaa humhug') == False
    assert match('baa*!', 'Sheep said baaa!') == False

    return 'test pass'

print(test())
