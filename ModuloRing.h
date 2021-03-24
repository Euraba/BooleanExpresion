class ModuloRing {
private:
    using i64 = long long ;
    int MODCLASS = 666013 ;
    i64 invMod(i64 base, int power) {
        i64 ret(1) ;
        i64 copyBase(base) ;
        for ( ; power ; power >>= 1) {
            if (power & 1) {
                ret = ret * copyBase % MODCLASS ;
            }
            copyBase = copyBase * copyBase % MODCLASS ;
        }
        return ret ;
    }
public:
    i64 value ;
    ModuloRing() {
        this -> value = 0 ;
    }
    ModuloRing(i64 _value, i64 MODD) {
        this -> value = _value ;
        MODCLASS = MODD ;
    }
    ModuloRing(ModuloRing const &_value) {
        this -> value = _value.value ;
    }
    ModuloRing operator + (int aux) const {
        ModuloRing ret ;
        ret.value = (this -> value + aux) % MODCLASS ;
        return ret;
    }
    ModuloRing operator + (ModuloRing aux) const {
        ModuloRing ret ;
        ret.value = (this -> value + aux.value) % MODCLASS ;
        return ret;
    }
    ModuloRing operator - (int aux) const {
        ModuloRing ret ;
        ret.value = this -> value - aux ;
        if (ret.value < 0) {
            int add(abs(ret.value) / MODCLASS + 1) ;
            ret.value += add * MODCLASS ;
        }
        ret.value %= MODCLASS ;
        return ret ;
    }
    ModuloRing operator - (const ModuloRing& aux) const {
        ModuloRing ret ;
        ret = *this - aux.value ;
        return ret;
    }
    ModuloRing operator * (int aux) const {
        ModuloRing ret ;
        ret.value = (this -> value * aux % MODCLASS) ;
        return ret;
    }
    ModuloRing operator *= (int aux) {
        *this = *this * aux ;
        return *this;
    }
    ModuloRing operator * (const ModuloRing& aux) const {
        ModuloRing ret ;
        ret = (*this * aux.value) ;
        return ret;
    }
    ModuloRing operator / (int aux) {
        i64 coef(invMod(aux, MODCLASS - 2)) ;
        ModuloRing ret = *this * coef ;
        return ret ;
    }
    ModuloRing operator /= (int aux) {
        *this = *this / aux ;
        return *this;
    }
    ModuloRing operator / (const ModuloRing& aux) {
        i64 coef(invMod(aux.value, MODCLASS - 2) % MODCLASS) ;
        ModuloRing ret = *this * coef ;
        return ret ;
    }
} ;
