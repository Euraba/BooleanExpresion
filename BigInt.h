class BigInt {
private :
    static const int MV = 3000;
    static const int BASE = 1000000;
    static const int BASE_LENGTH = 6;
    int v[MV + 1];
public :
    BigInt() {
      this->v[0] = 1;
      this->v[1] = 0;
      for (int i = 1; i < MV; ++i) {
        this->v[i] = 0;
      }
    }

    BigInt(int val) {
      this->v[0] = 0;
      for (int i = 1; i < MV; ++i) {
        this->v[i] = 0;
      }
      do {
        this->v[++this->v[0]] = val % BASE;
        val /= BASE;
      } while (val);
    }

    __attribute__ ((always_inline)) BigInt operator=(const BigInt &aux) {
      for (int i = 1; i <= aux.v[0]; ++i) {
        this->v[i] = aux.v[i];
      }
      for (int i = 1 + aux.v[0]; i <= v[0]; ++i) {
        v[i] = 0;
      }
      this->v[0] = aux.v[0];
      return *this;
    }

    __attribute__ ((always_inline)) BigInt operator*(int number) {
      int rest(0), i;
      BigInt ret;
      for (i = 1; i <= this->v[0] || rest; ++i) {
        ret.v[i] = this->v[i] * number + rest;
        rest = ret.v[i] / BASE;
        ret.v[i] %= BASE;
      }
      ret.v[0] = i - 1;
      return ret;
    }

    __attribute__ ((always_inline)) BigInt operator*=(int number) {
      *this = *this * number;
      return *this;
    }

    __attribute__ ((always_inline)) BigInt operator/(int number) {
      int rest(0), i;
      BigInt ret;
      ret.v[0] = this->v[0];
      for (i = this->v[0]; i > 0; --i) {
        rest = rest * BASE + this->v[i];
        ret.v[i] = rest / number;
        rest = rest % number;
      }
      for (; !ret.v[ret.v[0]]; --ret.v[0]);
      return ret;
    }

    __attribute__ ((always_inline)) BigInt operator/=(int number) {
      *this = *this / number;
      return *this;
    }

    __attribute__ ((always_inline)) BigInt operator=(int number) {
      this->v[0] = 0;
      do {
        this->v[++this->v[0]] = number % BASE;
        number /= BASE;
      } while (number);
      return *this;
    }

    __attribute__ ((always_inline)) BigInt operator+(const BigInt &aux) const {
      int rest(0), i;
      BigInt ret;
      for (i = 1; i <= this->v[0] || i <= aux.v[0] || rest; ++i) {
        ret.v[i] = this->v[i] + aux.v[i] + rest;
        rest = ret.v[i] / BASE;
        ret.v[i] %= BASE;
      }
      ret.v[0] = i - 1;
      return ret;
    }

    BigInt operator-(const BigInt &aux) const {
      int rest(0), i;
      BigInt ret;
      for (i = 1; i <= this->v[0] || i <= aux.v[0]; ++i) {
        ret.v[i] += this->v[i] - aux.v[i];
        if (ret.v[i] < 0) {
          ret.v[i] += BASE;
          ret.v[i + 1]--;
        }
      }
      ret.v[0] = i - 1;
      while (!ret.v[ret.v[0]]) {
        ret.v[0]--;
      }
      return ret;
    }

    __attribute__ ((always_inline)) BigInt operator+(int aux) const {
      int rest(0), i;
      BigInt ret;
      for (i = 1; i <= this->v[0] || rest; ++i) {
        ret.v[i] = this->v[i] + aux % BASE + rest;
        aux /= BASE;
        rest = ret.v[i] / BASE;
        ret.v[i] %= BASE;
      }
      ret.v[0] = i - 1;
      return ret;
    }

    __attribute__ ((always_inline)) BigInt operator-(int aux) const {
      int rest(0), i;
      BigInt ret;
      for (i = 1; i <= this->v[0]; ++i) {
        ret.v[i] = this->v[i] - aux % BASE;
        aux /= BASE;
        if (ret.v[i] < 0) {
          ret.v[i] += BASE;
          ret.v[i + 1]--;
        }
      }
      ret.v[0] = i - 1;
      return ret;
    }

    __attribute__ ((always_inline)) BigInt operator-=(const BigInt &aux) {
      *this = *this - aux;
      return *this;
    }

    __attribute__ ((always_inline)) friend std::ostream &operator<<(std::ostream &os, const BigInt &aux) {
      os << aux.v[aux.v[0]];
      for (int i = aux.v[0] - 1; i > 0; --i) {
        os << std::setfill('0') << std::setw(BASE_LENGTH) << aux.v[i];
      }
      return os;
    }
};
