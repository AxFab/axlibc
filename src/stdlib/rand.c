
// ---------------------------------------------------------------------------
/** seed for pseudo-random number */
unsigned int _seed = 1;

// ---------------------------------------------------------------------------
/** pseudo-random number generator */
int rand(void)
{
  _seed = _seed * 1103515245 + 12345;
  return (int)( _seed / 65536 ) % 32768;
}

// ---------------------------------------------------------------------------
/** reset seed for pseudo-random number */ 
void srand (unsigned int seed)
{
  _seed = seed;
}

