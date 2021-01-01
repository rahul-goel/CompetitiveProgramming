# CP Snippets
Quickly copy paste code from here.

## SQRT Prime Factorization
```c++
vector<int> sqrt_prime_factorize(int n) {
    vector<int> fac;

    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            fac.push_back(i);
            n /= i;
        }
    }

    if (n > 1) {
        fac.push_back(n);
    }

    return fac;
}
```

### Sieve
```c++
vector<int> get_sieve(int n) {
    vector<int> sieve(n);

    for (long long i = 2; i < (long long) n; i++) {
        sieve[i] = i;
        if (sieve[i] == 0) {
            for (long long j = i * i; j < (long long) n; j += i) {
                if (sieve[j] == 0) {
                    sieve[j] = i;
                }
            }
        }
    }

    return sieve;
}
```

### GCD and LCM
```c++
long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

long long lcm(long long a, long long b) {
    return a * b / gcd(a, b);
}

```
