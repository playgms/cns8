function modExp(base, exp, mod) {
    if (mod === 1) return 0;
    var result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 === 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1; // Divide exp by 2
        base = (base * base) % mod;
    }
    return result;
}

function checkPrime(n) {
    if (n <= 1) {
        return false;
    }
    for (let i = 2; i <= Math.floor(n / 2); i++) {
        if (n % i === 0) {
            return false; 
        }
    }
    return true; 
}

function generateKeys() {
    // Get the values from the input elements
    var alpha = parseInt(document.getElementById('alpha').value);
    var q = parseInt(document.getElementById('q').value);
    var Xa = parseInt(document.getElementById('Xa').value);
    var Xb = parseInt(document.getElementById('Xb').value);
    
    // Check if q is prime
    if (!checkPrime(q)) {
        document.getElementById('inputResult').innerText = q + " is not a prime number.";
        document.getElementById('Ya').textContent = "";
        document.getElementById('Yb').textContent = "";
        document.getElementById('Ka').textContent = "";
        document.getElementById('Kb').textContent = "";
        return;
    }
   
    // Calculate Ya and Yb using modular exponentiation
    var Ya = modExp(alpha, Xa, q);
    var Yb = modExp(alpha, Xb, q);

    // Calculate the shared secret keys
    var Ka = modExp(Yb, Xa, q); // Shared secret for User 1
    var Kb = modExp(Ya, Xb, q); // Shared secret for User 2

    // Display the results
    document.getElementById('Ya').textContent = Ya;
    document.getElementById('Yb').textContent = Yb;
    document.getElementById('Ka').textContent = Ka;
    document.getElementById('Kb').textContent = Kb;

    if (Ka == Kb) {
        document.getElementById('result').innerText = "Success! Shared secrets match.";
    } else {
        document.getElementById('result').innerText = "Error! Shared secrets do not match.";
    }
}
