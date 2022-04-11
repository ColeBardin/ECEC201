int my_function(int a, int b, int ceil)
{
    int foo;
    int bar;
    foo=a/2;
    bar=2*b;
    if(foo+bar>ceil)
            return(ceil);
    return (foo+bar);
}

int main()
{
    int foo=my_function(10,5,8);

    printf("%d\n",foo);
    return(0);
}
