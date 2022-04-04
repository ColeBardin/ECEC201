//Further modif of L2E4 to include float type
int foo(int bar,float baz)
{
  float n;
  int m=10;
  n=m+bar+baz;
  printf("n: %.1f\n",n);
  return(n);
}
int main()
{
foo(3,8.7);
return(0);
  }