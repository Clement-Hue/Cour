from typing import List, Set

alphabet = {'a', 'b', 'c', 'd'}


def tout(n):
    if n == 0:
        return ['']

    reste = tout(n - 1)
    liste = []
    for r in reste:
        for a in alphabet:
            liste.append(r + a)

    return liste


def words(A: Set[str], n: int) -> List[str]:
    assert n >= 0
    if n == 0:
        return [""]
    else:
        W = words(A, n - 1)
    return [a + w
            for a in A
            for w in W]


print(tout(2))
print("--------------")
print(words(alphabet, 2))
