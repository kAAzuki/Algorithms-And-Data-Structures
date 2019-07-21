#define EPS 1e-7
bool isprime(int x)
{
  if(x<=1) return false;
  if(x<=3) return true;
  if (!(x%2) || !(x%3)) return false;
  int s = (int)(sqrt((double)(x))+EPS);
  for(int i=5; i<=s; i+=6)
  {
    if (!(x%i) || !(x%(i+2))) return false;
  }
  return true;
}
