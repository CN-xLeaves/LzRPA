
  momentum_governor:
  ==================
  static sys i
  double sc
  @jball=#ball 'arraybase
  sc=gmass/(gmom*fac)
  for i=1 to nballs
    'LIMIT OVERALL SYSTEM MOMENTUM BY RESCALING EACH VELOCITY
    jball.vx*=sc
    jball.vy*=sc
    @jball+=sizeof ball
  next
  fstp st(0) ; flush scale factor
  ret

