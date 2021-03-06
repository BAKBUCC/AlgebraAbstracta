#include "Tools.h"

int Tools::modulo(int a, int n)
{
    if(n<0)
    {
        cout << "n es menor a 0" << endl;
        return 0;
    }
    int q = a / n;
    int r = a - (q * n);
    if (r < 0)
    {
        q--;
        r = a - (q * n);
    }
    return r;
}

ZZ Tools::modulo(ZZ a, ZZ n)
{
    if(n<0)
    {
        cout << "n es menor a 0" << endl;
        return ZZ(0);
    }
    ZZ q;
    q = a / n;
    ZZ r;
    r = a - (q * n);
    if (r < 0)
    {
        q--;
        r = a - (q * n);
    }
    return r;
}

int Tools::MCD(int  a, int  b)
{
    int r;
    r=modulo(a,b);
    while(r!=0)
    {
        r=modulo(a,b);
        if(r==0)
        {
            return b;
        }
        if(r > (b>>1))
        {
            r=b-r;
        }

        a=b;
        b=r;
    }
    return b;
}

ZZ Tools::MCD(ZZ  a, ZZ  b)
{
    ZZ r;
    r=modulo(a,b);
    while(r!=0)
    {
        r=modulo(a,b);
        if(r==0)
        {
            return b;
        }
        if(r > (b>>1))
        {
            r=b-r;
        }

        a=b;
        b=r;
    }
    return b;
}

int Tools::suma(int a, int b)
{
    return a + b;
}

int Tools::resta(int a, int b)
{
    cout << a << " " << b << endl;
    return a - b;
}

int Tools::multiplicacion(int a, int b)
{
    return a * b;
}

int Tools::ejecuta(int a, pf func, int b, int n)
{
    return func(modulo(a, n), modulo(b, n));
}

int Tools::XmodN_op_YmodN_todo_modN(int x, pf funcion, int y, int n)
{
    return modulo(ejecuta(x, funcion, y, n), n);
}

int Tools::inversa_mult_de_a_en_Zn(int n, int a)
{
    int r1 = n, r2 = a;
    int s1 = 1, s2 = 0;
    int t1 = 0, t2 = 1;
    int q, r, s, t;

    while (r2 > 0)
    {
        q = r1 / r2;

        r = r1 - (q * r2);
        r1 = r2; r2 = r;

        s = s1 - (q * s2);
        s1 = s2; s2 = s;

        t = t1 - (q * t2);
        t1 = t2; t2 = t;
    }
    s = s1; t = t1;
    return t;
}

ZZ Tools::inversa_mult_de_a_en_Zn(ZZ n, ZZ a)
{
    ZZ r1,r2;
    r1= n, r2 = a;
    ZZ s1,s2;
    s1 = 1, s2 = 0;
    ZZ t1,t2;
    t1 = 0, t2 = 1;
    ZZ q, r, s, t;

    while (r2 > 0)
    {
        q = r1 / r2;

        r = r1 - (q * r2);
        r1 = r2; r2 = r;

        s = s1 - (q * s2);
        s1 = s2; s2 = s;

        t = t1 - (q * t2);
        t1 = t2; t2 = t;
    }
    s = s1; t = t1;
    return t;
}

void Tools::print_AlgoritmoExtendido_Euclides(int a, int b)
{
    int r1 = a, r2 = b;
    int s1 = 1, s2 = 0;
    int t1 = 0, t2 = 1;
    int q, r, s, t;
    int mcd_a_b;

    while (r2 > 0)
    {
        q = r1 / r2;

        r = r1 - (q * r2);
        r1 = r2; r2 = r;

        s = s1 - (q * s2);
        s1 = s2; s2 = s;

        t = t1 - (q * t2);
        t1 = t2; t2 = t;
    }
    mcd_a_b = r1; s = s1; t = t1;
    cout << "mcd(a,b): " << mcd_a_b << "=" << a << "(x) + " << b << "(y)" << endl;
    cout << "x: " << s << endl;
    cout << "y: " << t << endl;
}

int Tools::Print_mcd(int a, int b)
{
    cout << a << " = " << a / b << "(" << b << ")";
    int* r = new int;
    *r = modulo(a, b);
    cout << " + " << *r << endl;

    if (*r == 0)
    {
        return b;
    }
    else
    {
        a = b;
        b = *r;
    }
    delete r;
    return Print_mcd(a, b);
}

void Tools::Print_Inversas_Add(int conjuntoZ)
{
    for (int i = 1; i < conjuntoZ; i++)
    {
        for (int j = 1; j < conjuntoZ; j++)
        {
            if (modulo(i + j, conjuntoZ) == 0)
            {
                cout << "(" << i << "+" << j << ") mod " << conjuntoZ << "= 0\n";
            }
        }
    }
}

void Tools::Print_Inversas_Mult(int conjuntoZ)
{
    for (int i = 0; i < conjuntoZ; i++)
    {
        for (int j = 0; j < conjuntoZ; j++)
        {
            if (modulo(i * j, conjuntoZ) == 1)
            {
                cout << "{" << i << "," << j << "}\n";
            }
        }
    }
}

long long Tools::Num_Aleatorio(long long maxi)
{
	random_device dev;
	mt19937 rng(dev());
	uniform_int_distribution<mt19937::result_type> random(0, maxi);
	return random(rng);
}

ZZ Tools::pow(ZZ base, ZZ exp)
{
    ZZ result;
    result=1;
    while(exp!=0)
    {
        result*=base;
        exp--;
    }
    return result;
}

ZZ Tools::pow_base_exp__modulo_mod(ZZ base, ZZ exp, ZZ mod)
{
    ZZ result;
    result=1;
    base=modulo(base,mod);
    if(modulo(exp, ZZ(2))==1)
    {
        result=base;
    }
    exp/=2;
    ZZ elevado;
    while(exp!=0)
    {
        elevado = pow(base, ZZ(2));
        base = modulo(elevado, mod);
        if(modulo(exp, ZZ(2))==1)
        {
            result=modulo(result*base,mod);
        }
        exp/=2;
    }
    return result;
}

void Tools::Generar_num_Primos_hasta_n_en_vector_v(const long long n, Vec<ZZ>& v)
{
    long long i,s,j,index;
    int r;
    cout<<"hola";
    bitset <n/2> noPrimo;
    noPrimo.reset();
    cout<<"hello";
    v[0]=2;
    v[1]=3;

    for (i = 5, r = 2, index=2; i <= n; i += r, r = 6 - r) {//i avanza (5, 7, 11, 13, 17 ...) +2,+4,+2,+4,...para no tomar los valores multiplos de 2 y 3.

        if (!noPrimo.test(i/3)) {
                v[index]=i;
                index++;

            for (j = i * i, s = r; j < n; j +=(s * i), s = 6 - s)
                noPrimo.set(j/3);
        }
    }
}
