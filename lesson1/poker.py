
def poker(hands):
    return max(hands, key=hand_rank)


def card_ranks(hand):
    ranks = ['--23456789TJQKA'.index(r) for r,s in hand]
    ranks.sort(reverse=True)
    return [5, 4, 3, 2, 1] if ranks == [14, 5, 4, 3, 2] else ranks


def straight(ranks):
    return (max(ranks) - min(ranks) == 4) and (len(set(ranks)) == 5)


def flush(hand):
    suits = [s for r, s in hand]
    return len(set(suits)) == 1


def kind(n, ranks):
    for r in ranks:
        if ranks.count(r) == n: return r
    return None


def two_pair(ranks):
    pair = kind(2, ranks)
    lowpair = kind(2, list(reversed(ranks)))
    if pair != lowpair:
        return pair, lowpair
    else:
        return None


def hand_rank(hand):
    ranks = card_ranks(hand)
    if straight(ranks) and flush(hand):
        return 8, max(ranks)
    elif kind(4, ranks):
        return 7, kind(4, ranks), kind(1, ranks)
    elif kind(3, ranks) and kind(2, ranks):
        return 6, kind(3, ranks), kind(2, ranks)
    elif flush(hand):
        return 5, flush(hand)
    elif straight(ranks):
        return 4, max(ranks)
    elif kind(3, ranks):
        return 3, kind(3, hand), kind(1, ranks), kind(1, ranks)
    elif two_pair(ranks):
        return 2, kind(2, ranks), kind(2, ranks), kind(1, ranks)
    elif kind(2, ranks):
        return 1, kind(2, ranks), kind(1, ranks), kind(1, ranks), kind(1, ranks)
    else:
        return 0, ranks


def test():
    sf = '6C 7C 8C 9C TC'.split()
    fk = '9D 9H 9S 9C 7D'.split()
    fh = 'TD TC TH 7C 7D'.split()
    tp = '5S 5D 9H 9C 6S'.split()
    s1 = 'AS 2S 3S 4S 5S'.split()
    s2 = '2C 3C 4C 5S 6C'.split()
    ah = 'As 2S 3S 4S 6C'.split()
    sh = '2S 3S 4S 6C 7D'.split()

    assert poker([sf, fk, fh]) == sf
    assert poker([fk, fh]) == fk
    assert poker([fh, fh]) == fh
    assert hand_rank(sf) == (8, 10)
    assert hand_rank(fk) == (7, 9, 7)
    assert hand_rank(fh) == (6, 10, 7)
    return "test pass"


print(test())
