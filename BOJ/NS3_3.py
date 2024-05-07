import os


class ECurve(object):

    def __init__(self, a, b, p):
        self.a = a
        self.b = b
        self.p = p

    def inf(self):
        return ECPoint(curve=self, x=None, y=None)

    def __eq__(self, other):
        return self.a == other.a and self.b == other.b and self.p == other.p


class ECPoint(object):

    def __init__(self, curve, x, y):
        self.curve = curve
        self.x = x
        self.y = y

    def copy(self):
        return ECPoint(curve=self.curve, x=self.x, y=self.y)

    def is_inf(self):
        return self == self.curve.inf()

    def __eq__(self, other):
        return self.curve == other.curve and self.x == other.x and self.y == other.y

    # Point multiplication
    def __mul__(self, s):
        bits = [s & (1 << i) for i in range(s.bit_length()-1, -1, -1)]
        res = self.curve.inf()
        for bit in bits:
            res = res + res
            if bit:
                res = res + self
        return res

    # Point addition
    def __add__(self, other):
        if self.is_inf():
            return other.copy()
        if other.is_inf():
            return self.copy()
        x1, y1 = self.x, self.y
        x2, y2 = other.x, other.y
        p = self.curve.p
        if x1 % p == x2 % p and y1 % p == (-y2) % p:
            return self.curve.inf()
        if self != other:
            s = (y2 - y1) * pow(x2 - x1, -1, p) % p
        else:
            # Point doubling
            s = (3 * pow(x1, 2) + self.curve.a) * pow(2 * y1, -1, p) % p
        x3 = (pow(s, 2) - x1 - x2) % p
        y3 = (s * (x1 - x3) - y1) % p
        return ECPoint(curve=self.curve, x=x3, y=y3)


# NIST FIBS PUB 186-4, B.4.2 p. 63
def generate_random_p_256_secret(n):
    candidate = 0
    while not 0 < candidate < n:
        candidate = int.from_bytes(os.urandom((n.bit_length() + 7) // 8), 'big')
    return candidate


if __name__ == "__main__":

    # NIST P-256, SP 800-186, chapter 4.2.1.3 page 13
    p = 23
    n = 22
    a = 1
    b = 1
    g_x = 5
    g_y = 7

    # Create P-256 elliptic curve and generator point
    p_256_curve = ECurve(a, b, p)
    G = ECPoint(p_256_curve, g_x, g_y)

    # Public-private key of Alice
    private_key_alice = generate_random_p_256_secret(p)
    public_key_alice = G * private_key_alice

    # Public-private key of Bob
    private_key_bob = generate_random_p_256_secret(p)
    public_key_bob = G * private_key_bob

    # Shared key of Alice
    shared_key_alice = public_key_bob * private_key_alice

    # Shared key of Bob
    shared_key_bob = public_key_alice * private_key_bob

    # Verify both Alice and Bob arrived at the same shared key
    assert (shared_key_alice == shared_key_bob)
    print(shared_key_alice)
    print(shared_key_bob)