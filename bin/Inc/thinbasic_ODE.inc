  '=============================================================================
  '=                         ODE headers for thinBasic                         =
  '=                                                                           =
  '=                           Petr Schreiber, 2007                            =
  '=                                                                           =
  '=                          THIRD OFFICIAL RELEASE                           =
  '=============================================================================
  

  '=============================================================================
  '=                                 config.h                                  =
  '=============================================================================

  ALIAS SINGLE AS dReal
  alias dword  as dWorldID
  alias dword  as dGeomID
  alias dword  as dSpaceID
  alias dword  as dJointID
  alias dword  as dBodyID
  alias dword  as DJOINTGROUPID 
  alias dword  as dJointFeedbackID 
  alias dword  as dJointFeedback
  alias dword  as dNearCallback
  alias dword  as dxTriMeshData
  alias dword  as dTriMeshDataID
  alias dword  as dTriArrayCallback
  alias dword  as dTriCallback
  alias dword  as dTriRayCallback
  alias dword  as dHeightfieldDataID
  alias dword  as DHEIGHTFIELDGETHEIGHT
  alias single  as float
  
  '=============================================================================
  '=                                 contact.h                                 =
  '=============================================================================

  global dContactMu2      as long = &h001
  global dContactFDir1    as long = &h002
  global dContactBounce   as long = &h004
  global dContactSoftERP  as long = &h008
  global dContactSoftCFM  as long = &h010
  global dContactMotion1  as long = &h020
  global dContactMotion2  as long = &h040
  global dContactSlip1    as long = &h080
  global dContactSlip2    as long = &h100

  global dContactApprox0    as long = &h0000
  global dContactApprox1_1  as long = &h1000
  global dContactApprox1_2  as long = &h2000
  global dContactApprox1    as long = &h3000
  
  TYPE dSurfaceParameters 
    ' must always be defined 
    mode  as long
    mu    as dReal
    ' only defined if the corresponding flag is set in mode 
    mu2   as dReal
    bounce      as dReal
    bounce_vel  as dReal
    soft_erp    as dReal
    soft_cfm    as dReal
    motion1     as dReal
    motion2     as dReal
    slip1       as dReal
    slip2       as dReal
  end type

  '*
  '* @brief Describe the contact point between two geoms.
  '*
  '* If two bodies touch, or if a body touches a static feature in its 
  '* environment, the contact is represented by one or more "contact 
  '* points", described by dContactGeom.
  '*
  '* The convention is that if body 1 is moved along the normal vector by 
  '* a distance depth (or equivalently if body 2 is moved the same distance 
  '* in the opposite direction) then the contact depth will be reduced to 
  '* zero. This means that the normal vector points "in" to body 1.
  '*
  '* @ingroup collide
  '*
  
  type dContactGeom 
    pos(4)    as dReal  'contact position
    normal(4) as dReal  ' normal vector
    depth     as dReal  ' penetration depth
    g1        as dword
    g2        as dword  ' the colliding geoms
    side1     as long
    side2     as long   ' (to be documented)
  end type

  ' contact info used by contact joint 

  type dContact
    surface as dSurfaceParameters
    geom    as dContactGeom    
    fdir1(4)   as dReal
  end type
  
  '=============================================================================
  '=                                  mass.h                                   =
  '=============================================================================
  
  ' Mass
  TYPE dMass
    mass  AS dReal
    c(4)  AS dReal
    I(4*3)AS dReal
  END TYPE
  
    '**
  '* Check if a mass structure has valid value.
  '* The function check if the mass and innertia matrix are positive definits
  '*
  '* @param m A mass structure to check
  '*
  '* @return 1 if both codition are met
  '*
  
  DECLARE FUNCTION  dMassCheck LIB "ode.dll" ALIAS "dMassCheck" (BYREF m AS dMass) AS LONG

  DECLARE SUB dMassSetZero  LIB "ode.dll" ALIAS "dMassSetZero" (BYREF dMassID AS dMass)

  DECLARE SUB dMassSetParameters  LIB "ode.dll" ALIAS "dMassSetParameters" (BYREF dMassID AS dMass, BYVAL themass AS dReal, BYVAL cgx AS dReal, BYVAL cgy AS dReal, BYVAL cgz AS dReal, BYVAL I11 AS dReal, BYVAL I22 AS dReal, BYVAL I33 AS dReal, BYVAL I12 AS dReal, BYVAL I13 AS dReal, BYVAL I23 AS dReal)


  DECLARE SUB dMassSetSphere  LIB "ode.dll" ALIAS "dMassSetSphere" (BYREF dMassID AS dMass, BYVAL density AS dReal, BYVAL radius AS dReal)
  DECLARE SUB dMassSetSphereTotal  LIB "ode.dll" ALIAS "dMassSetSphereTotal" (BYREF dMassID AS dMass, BYVAL total_mass AS dReal, BYVAL radius AS dReal)

  DECLARE SUB dMassSetCapsule  LIB "ode.dll" ALIAS "dMassSetCapsule" (BYREF dMassID AS dMass, BYVAL density AS dReal, BYVAL direction AS LONG, BYVAL radius AS dReal, BYVAL length AS dReal)

  DECLARE SUB dMassSetCapsuleTotal  LIB "ode.dll" ALIAS "dMassSetCapsuleTotal" (BYREF dMassID AS dMass, BYVAL total_mass AS dReal, BYVAL direction AS LONG, BYVAL radius AS dReal, BYVAL length AS dReal)


  DECLARE SUB dMassSetCylinder  LIB "ode.dll" ALIAS "dMassSetCylinder" (BYREF dMassID AS dMass, BYVAL density AS dReal, BYVAL direction AS LONG, BYVAL radius AS dReal, BYVAL length AS dReal)

  DECLARE SUB dMassSetCylinderTotal  LIB "ode.dll" ALIAS "dMassSetCylinderTotal" (BYREF dMassID AS dMass, BYVAL total_mass AS dReal, BYVAL direction AS LONG, BYVAL radius AS dReal, BYVAL length AS dReal)


  DECLARE SUB dMassSetBox  LIB "ode.dll" ALIAS "dMassSetBox" (BYREF dMassID AS dMass, BYVAL density AS dReal, BYVAL lx AS dReal, BYVAL ly AS dReal, BYVAL lz AS dReal)

  DECLARE SUB dMassSetBoxTotal  LIB "ode.dll" ALIAS "dMassSetBoxTotal" (BYREF dMassID AS dMass, BYVAL total_mass AS dReal, BYVAL lx AS dReal, BYVAL ly AS dReal, BYVAL lz AS dReal)


  DECLARE SUB dMassSetTrimesh  LIB "ode.dll" ALIAS "dMassSetTrimesh" (BYREF dMassID AS dMass, BYVAL density AS dReal, BYVAL g AS dGeomID)

  DECLARE SUB dMassAdjust  LIB "ode.dll" ALIAS "dMassAdjust" (BYREF dMassID AS dMass, BYVAL newmass AS dReal)

  DECLARE SUB dMassTranslate  LIB "ode.dll" ALIAS "dMassTranslate" (BYREF dMassID AS dMass, BYVAL x AS dReal, BYVAL y AS dReal, BYVAL z AS dReal)

  DECLARE SUB dMassRotate  LIB "ode.dll" ALIAS "dMassRotate" (BYREF dMassID AS dMass, BYVAL R() AS dReal)

  DECLARE SUB dMassAdd  LIB "ode.dll" ALIAS "dMassAdd" (BYREF a AS dMass, BYREF b AS dMass)
  
  ' Backwards compatible API ???
  '#define dMassSetCappedCylinder dMassSetCapsule
  '#define dMassSetCappedCylinderTotal dMassSetCapsuleTotal

  '=============================================================================
  '=                                 objects.h                                 =
  '=============================================================================



  '/**

  '* @defgroup world World

  '*

  '* The world object is a container for rigid bodies and joints. Objects in

  '* different worlds can not interact, for example rigid bodies from two

  '* different worlds can not collide.

  '*

  '* All the objects in a world exist at the same point in time, thus one

  '* reason to use separate worlds is to simulate systems at different rates.

  '* Most applications will only need one world.

  '*/





  '/**

  '* @brief Create a new, empty world and return its ID number.

  '* @return an identifier

  '* @ingroup world

  '*/

  DECLARE FUNCTION  dWorldCreate LIB "ode.dll" ALIAS "dWorldCreate" () AS dWorldID





  '/**

  '* @brief Destroy a world and everything in it.

  '*

  '* This includes all bodies, and all joints that are not part of a joint

  '* group. Joints that are part of a joint group will be deactivated, and

  '* can be destroyed by calling, for example, dJointGroupEmpty().

  '* @ingroup world

  '* @param world the identifier for the world the be destroyed.

  '*/

  DECLARE SUB dWorldDestroy  LIB "ode.dll" ALIAS "dWorldDestroy" (BYVAL world AS dWorldID)





  '/**

  '* @brief Set the world's global gravity vector.

  '*

  '* The units are m/s^2, so Earth's gravity vector would be (0,0,-9.81),* assuming that +z is up. The default is no gravity, i.e. (0,0,0).



  '*

  '* @ingroup world

  '*/

  DECLARE SUB dWorldSetGravity  LIB "ode.dll" ALIAS "dWorldSetGravity" (BYVAL dWorldIDlike AS dWorldID, BYVAL x AS dReal, BYVAL y AS dReal, BYVAL z AS dReal)





  '/**

  '* @brief Get the gravity vector for a given world.

  '* @ingroup world

  '*/

  DECLARE SUB dWorldGetGravity  LIB "ode.dll" ALIAS "dWorldGetGravity" (BYVAL dWorldIDlike AS dWorldID, BYVAL gravity() AS dReal)





  '/**

  '* @brief Set the global ERP value, that controls how much error

  '* correction is performed in each time step.

  '* @ingroup world

  '* @param dWorldID the identifier of the world.

  '* @param erp Typical values are in the range 0.1--0.8. The default is 0.2.

  '*/

  DECLARE SUB dWorldSetERP  LIB "ode.dll" ALIAS "dWorldSetERP" (BYVAL dWorldIDlike AS dWorldID, BYVAL erp AS dReal)



  '/**

  '* @brief Get the error reduction parameter.

  '* @ingroup world

  '* @return ERP value

  '*/

  DECLARE FUNCTION  dWorldGetERP  LIB "ode.dll" ALIAS "dWorldGetERP" (BYVAL dWorldIDlike AS dWorldID) AS dReal





  '/**

  '* @brief Set the global CFM (constraint force mixing) value.

  '* @ingroup world

  '* @param cfm Typical values are in the range @m{10^{-9}} -- 1.

  '* The default is 10^-5 if single precision is being used, or 10^-10

  '* if double precision is being used.

  '*/

  DECLARE SUB dWorldSetCFM  LIB "ode.dll" ALIAS "dWorldSetCFM" (BYVAL dWorldIDlike AS dWorldID, BYVAL cfm AS dReal)



  '/**

  '* @brief Get the constraint force mixing value.

  '* @ingroup world

  '* @return CFM value

  '*/

  DECLARE FUNCTION  dWorldGetCFM  LIB "ode.dll" ALIAS "dWorldGetCFM" (BYVAL dWorldIDlike AS dWorldID) AS dReal





  '/**

  '* @brief Step the world.

  '*

  '* This uses a "big matrix" method that takes time on the order of m^3

  '* and memory on the order of m^2, where m is the total number of constraint

  '* rows. For large systems this will use a lot of memory and can be very slow,* but this is currently the most accurate method.



  '* @ingroup world

  '* @param stepsize The number of seconds that the simulation has to advance.

  '*/

  DECLARE SUB dWorldStep  LIB "ode.dll" ALIAS "dWorldStep" (BYVAL dWorldIDlike AS dWorldID, BYVAL stepsize AS dReal)





  '/**

  '* @brief Converts an impulse to a force.

  '* @ingroup world

  '* @remarks

  '* If you want to apply a linear or angular impulse to a rigid body,* instead of a force or a torque, then you can use this function to convert



  '* the desired impulse into a force/torque vector before calling the

  '* BodyAdd... function.

  '* The current algorithm simply scales the impulse by 1/stepsize,* where stepsize is the step size for the next step that will be taken.



  '* This function is given a dWorldID because, in the future, the force

  '* computation may depend on integrator parameters that are set as

  '* properties of the world.

  '*/

  DECLARE SUB dWorldImpulseToForce   LIB "ode.dll" ALIAS "dWorldImpulseToForce" ( byval dWorldIDlike as dWorldID, byval stepsize as dReal, byval ix as dReal, byval iy as dReal, byval iz as dReal, byval force() as dReal )





  '/**

  '* @brief Step the world.

  '* @ingroup world

  '* @remarks

  '* This uses an iterative method that takes time on the order of m*N

  '* and memory on the order of m, where m is the total number of constraint

  '* rows N is the number of iterations.

  '* For large systems this is a lot faster than dWorldStep(),* but it is less accurate.



  '* @remarks

  '* QuickStep is great for stacks of objects especially when the

  '* auto-disable feature is used as well.

  '* However, it has poor accuracy for near-singular systems.

  '* Near-singular systems can occur when using high-friction contacts, motors,* or certain articulated structures. For example, a robot with multiple legs



  '* sitting on the ground may be near-singular.

  '* @remarks

  '* There are ways to help overcome QuickStep's inaccuracy problems:

  '* \li Increase CFM.

  '* \li Reduce the number of contacts in your system (e.g. use the minimum

  '* number of contacts for the feet of a robot or creature).

  '* \li Don't use excessive friction in the contacts.

  '* \li Use contact slip if appropriate

  '* \li Avoid kinematic loops (however, kinematic loops are inevitable in

  '* legged creatures).

  '* \li Don't use excessive motor strength.

  '* \liUse force-based motors instead of velocity-based motors.

  '*

  '* Increasing the number of QuickStep iterations may help a little bit, but

  '* it is not going to help much if your system is really near singular.

  '*/

  DECLARE SUB dWorldQuickStep  LIB "ode.dll" ALIAS "dWorldQuickStep" (BYVAL w AS dWorldID, BYVAL stepsize AS dReal)





  '/**

  '* @brief Set the number of iterations that the QuickStep method performs per

  '* step.

  '* @ingroup world

  '* @remarks

  '* More iterations will give a more accurate solution, but will take

  '* longer to compute.

  '* @param num The default is 20 iterations.

  '*/

  DECLARE SUB dWorldSetQuickStepNumIterations  LIB "ode.dll" ALIAS "dWorldSetQuickStepNumIterations" (BYVAL dWorldIDlike AS dWorldID, BYVAL num AS LONG)





  '/**

  '* @brief Get the number of iterations that the QuickStep method performs per

  '* step.

  '* @ingroup world

  '* @return nr of iterations

  '*/

  DECLARE FUNCTION  dWorldGetQuickStepNumIterations  LIB "ode.dll" ALIAS "dWorldGetQuickStepNumIterations" (BYVAL dWorldIDlike AS dWorldID) AS LONG



  '/**

  '* @brief Set the SOR over-relaxation parameter

  '* @ingroup world

  '* @param over_relaxation value to use by SOR

  '*/

  DECLARE SUB dWorldSetQuickStepW  LIB "ode.dll" ALIAS "dWorldSetQuickStepW" (BYVAL dWorldIDlike AS dWorldID, BYVAL over_relaxation AS dReal)



  '/**

  '* @brief Get the SOR over-relaxation parameter

  '* @ingroup world

  '* @returns the over-relaxation setting

  '*/

  DECLARE FUNCTION  dWorldGetQuickStepW  LIB "ode.dll" ALIAS "dWorldGetQuickStepW" (BYVAL dWorldIDlike AS dWorldID) AS dReal



  '/* World contact parameter functions */



  '/**

  '* @brief Set the maximum correcting velocity that contacts are allowed

  '* to generate.

  '* @ingroup world

  '* @param vel The default value is infinity (i.e. no limit).

  '* @remarks

  '* Reducing this value can help prevent "popping" of deeply embedded objects.

  '*/

  DECLARE SUB dWorldSetContactMaxCorrectingVel  LIB "ode.dll" ALIAS "dWorldSetContactMaxCorrectingVel" (BYVAL dWorldIDlike AS dWorldID, BYVAL vel AS dReal)



  '/**

  '* @brief Get the maximum correcting velocity that contacts are allowed

  '* to generated.

  '* @ingroup world

  '*/

  DECLARE FUNCTION  dWorldGetContactMaxCorrectingVel  LIB "ode.dll" ALIAS "dWorldGetContactMaxCorrectingVel" (BYVAL dWorldIDlike AS dWorldID) AS dReal



  '/**

  '* @brief Set the depth of the surface layer around all geometry objects.

  '* @ingroup world

  '* @remarks

  '* Contacts are allowed to sink into the surface layer up to the given

  '* depth before coming to rest.

  '* @param depth The default value is zero.

  '* @remarks

  '* Increasing this to some small value (e.g. 0.001) can help prevent

  '* jittering problems due to contacts being repeatedly made and broken.

  '*/

  DECLARE SUB dWorldSetContactSurfaceLayer  LIB "ode.dll" ALIAS "dWorldSetContactSurfaceLayer" (BYVAL dWorldIDlike AS dWorldID, BYVAL depth AS dReal)



  '/**

  '* @brief Get the depth of the surface layer around all geometry objects.

  '* @ingroup world

  '* @returns the depth

  '*/

  DECLARE FUNCTION  dWorldGetContactSurfaceLayer  LIB "ode.dll" ALIAS "dWorldGetContactSurfaceLayer" (BYVAL dWorldIDlike AS dWorldID) AS dReal



  '/* StepFast1 functions */



  '/**

  '* @brief Step the world using the StepFast1 algorithm.

  '* @param stepsize the nr of seconds to advance the simulation.

  '* @param maxiterations The number of iterations to perform.

  '* @ingroup world

  '*/

  DECLARE SUB dWorldStepFast1 LIB "ode.dll" ALIAS "dWorldStepFast1" (BYVAL dWorldIDlike AS dWorldID, BYVAL stepsize AS dReal, BYVAL maxiterations AS LONG)





  '/**

  '* @defgroup disable Automatic Enabling and Disabling

  '*

  '* Every body can be enabled or disabled. Enabled bodies participate in the

  '* simulation, while disabled bodies are turned off and do not get updated

  '* during a simulation step. New bodies are always created in the enabled state.

  '*

  '* A disabled body that is connected through a joint to an enabled body will be

  '* automatically re-enabled at the next simulation step.

  '*

  '* Disabled bodies do not consume CPU time, therefore to speed up the simulation

  '* bodies should be disabled when they come to rest. This can be done automatically

  '* with the auto-disable feature.

  '*

  '* If a body has its auto-disable flag turned on, it will automatically disable

  '* itself when

  '* @li It has been idle for a given number of simulation steps.

  '* @li It has also been idle for a given amount of simulation time.

  '*

  '* A body is considered to be idle when the magnitudes of both its

  '* linear average velocity and angular average velocity are below given thresholds.

  '* The sample size for the average defaults to one and can be disabled by setting

  '* to zero with

  '*

  '* Thus, every body has six auto-disable parameters: an enabled flag, a idle step

  '* count, an idle time, linear/angular average velocity thresholds, and the

  '* average samples count.

  '*

  '* Newly created bodies get these parameters from world.

  '*/



  '/**

  '* @brief Set the AutoEnableDepth parameter used by the StepFast1 algorithm.

  '* @ingroup disable

  '*/

  DECLARE SUB dWorldSetAutoEnableDepthSF1 LIB "ode.dll" ALIAS "dWorldSetAutoEnableDepthSF1" (BYVAL dWorldIDlike AS dWorldID, BYVAL autoEnableDepth AS LONG)



  '/**

  '* @brief Get the AutoEnableDepth parameter used by the StepFast1 algorithm.

  '* @ingroup disable

  '*/

  DECLARE FUNCTION  dWorldGetAutoEnableDepthSF1 LIB "ode.dll" ALIAS "dWorldGetAutoEnableDepthSF1" (BYVAL dWorldIDlike AS dWorldID) AS LONG



  '/**

  '* @brief Get auto disable linear threshold for newly created bodies.

  '* @ingroup disable

  '* @return the threshold

  '*/

  DECLARE FUNCTION  dWorldGetAutoDisableLinearThreshold  LIB "ode.dll" ALIAS "dWorldGetAutoDisableLinearThreshold" (BYVAL dWorldIDlike AS dWorldID) AS dReal



  '/**

  '* @brief Set auto disable linear threshold for newly created bodies.

  '* @param linear_threshold default is 0.01

  '* @ingroup disable

  '*/

  DECLARE SUB dWorldSetAutoDisableLinearThreshold  LIB "ode.dll" ALIAS "dWorldSetAutoDisableLinearThreshold" (BYVAL dWorldIDlike AS dWorldID, BYVAL linear_threshold AS dReal)



  '/**

  '* @brief Get auto disable angular threshold for newly created bodies.

  '* @ingroup disable

  '* @return the threshold

  '*/

  DECLARE FUNCTION  dWorldGetAutoDisableAngularThreshold  LIB "ode.dll" ALIAS "dWorldGetAutoDisableAngularThreshold" (BYVAL dWorldIDlike AS dWorldID) AS dReal



  '/**

  '* @brief Set auto disable angular threshold for newly created bodies.

  '* @param linear_threshold default is 0.01

  '* @ingroup disable

  '*/

  DECLARE SUB dWorldSetAutoDisableAngularThreshold  LIB "ode.dll" ALIAS "dWorldSetAutoDisableAngularThreshold" (BYVAL dWorldIDlike AS dWorldID, BYVAL angular_threshold AS dReal)



  '/**

  '* @brief Get auto disable linear average threshold for newly created bodies.

  '* @ingroup disable

  '* @return the threshold

  '*/

' ???  DECLARE FUNCTION  dWorldGetAutoDisableLinearAverageThreshold  LIB "ode.dll" ALIAS "dWorldGetAutoDisableLinearAverageThreshold" (BYVAL dWorldIDlike AS dWorldID) AS dReal



  '/**

  '* @brief Set auto disable linear average threshold for newly created bodies.

  '* @param linear_average_threshold default is 0.01

  '* @ingroup disable

  '*/

' ???  DECLARE SUB dWorldSetAutoDisableLinearAverageThreshold  LIB "ode.dll" ALIAS "dWorldSetAutoDisableLinearAverageThreshold" (BYVAL dWorldIDlike AS dWorldID, BYVAL linear_average_threshold AS dReal)



  '/**

  '* @brief Get auto disable angular average threshold for newly created bodies.

  '* @ingroup disable

  '* @return the threshold

  '*/

' ???  DECLARE FUNCTION  dWorldGetAutoDisableAngularAverageThreshold  LIB "ode.dll" ALIAS "dWorldGetAutoDisableAngularAverageThreshold" (BYVAL dWorldIDlike AS dWorldID) AS dReal



  '/**

  '* @brief Set auto disable angular average threshold for newly created bodies.

  '* @param linear_average_threshold default is 0.01

  '* @ingroup disable

  '*/

' ???  DECLARE SUB dWorldSetAutoDisableAngularAverageThreshold  LIB "ode.dll" ALIAS "dWorldSetAutoDisableAngularAverageThreshold" (BYVAL dWorldIDlike AS dWorldID, BYVAL angular_average_threshold AS dReal)



  '/**

  '* @brief Get auto disable sample count for newly created bodies.

  '* @ingroup disable

  '* @return number of samples used

  '*/

  DECLARE FUNCTION  dWorldGetAutoDisableAverageSamplesCount  LIB "ode.dll" ALIAS "dWorldGetAutoDisableAverageSamplesCount" (BYVAL dWorldIDlike AS dWorldID) AS LONG



  '/**

  '* @brief Set auto disable average sample count for newly created bodies.

  '* @ingroup disable

  '* @param average_samples_count Default is 1, meaning only instantaneous velocity is used.

  '* Set to zero to disable sampling and thus prevent any body from auto-disabling.

  '*/

' ???  DECLARE SUB dWorldSetAutoDisableAverageSamplesCount  LIB "ode.dll" ALIAS "dWorldSetAutoDisableAverageSamplesCount" (BYVAL dWorldIDlike AS dWorldID, BYVAL average_samples_count AS dword)



  '/**

  '* @brief Get auto disable steps for newly created bodies.

  '* @ingroup disable

  '* @return nr of steps

  '*/

  DECLARE FUNCTION  dWorldGetAutoDisableSteps  LIB "ode.dll" ALIAS "dWorldGetAutoDisableSteps" (BYVAL dWorldIDlike AS dWorldID) AS LONG



  '/**

  '* @brief Set auto disable steps for newly created bodies.

  '* @ingroup disable

  '* @param steps default is 10

  '*/

  DECLARE SUB dWorldSetAutoDisableSteps  LIB "ode.dll" ALIAS "dWorldSetAutoDisableSteps" (BYVAL dWorldIDlike AS dWorldID, BYVAL steps AS LONG)



  '/**

  '* @brief Get auto disable time for newly created bodies.

  '* @ingroup disable

  '* @return nr of seconds

  '*/

  DECLARE FUNCTION  dWorldGetAutoDisableTime  LIB "ode.dll" ALIAS "dWorldGetAutoDisableTime" (BYVAL dWorldIDlike AS dWorldID) AS dReal



  '/**

  '* @brief Set auto disable time for newly created bodies.

  '* @ingroup disable

  '* @param time default is 0 seconds

  '*/

  DECLARE SUB dWorldSetAutoDisableTime  LIB "ode.dll" ALIAS "dWorldSetAutoDisableTime" (BYVAL dWorldIDlike AS dWorldID, BYVAL time AS dReal)



  '/**

  '* @brief Get auto disable flag for newly created bodies.

  '* @ingroup disable

  '* @return 0 or 1

  '*/

  DECLARE FUNCTION  dWorldGetAutoDisableFlag  LIB "ode.dll" ALIAS "dWorldGetAutoDisableFlag" (BYVAL dWorldIDlike AS dWorldID) AS LONG



  '/**

  '* @brief Set auto disable flag for newly created bodies.

  '* @ingroup disable

  '* @param do_auto_disable default is false.

  '*/

  DECLARE SUB dWorldSetAutoDisableFlag  LIB "ode.dll" ALIAS "dWorldSetAutoDisableFlag" (BYVAL dWorldIDlike AS dWorldID, BYVAL do_auto_disable AS LONG)







  '/**

  '* @defgroup bodies Rigid Bodies

  '*

  '* A rigid body has various properties from the point of view of the

  '* simulation. Some properties change over time:

  '*

  '* @li Position vector (x,y,z) of the body's point of reference.

  '* Currently the point of reference must correspond to the body's center of mass.

  '* @li Linear velocity of the point of reference, a vector (vx,vy,vz).

  '* @li Orientation of a body, represented by a quaternion (qs,qx,qy,qz) or

  '* a 3x3 rotation matrix.

  '* @li Angular velocity vector (wx,wy,wz) which describes how the orientation

  '* changes over time.

  '*

  '* Other body properties are usually constant over time:

  '*

  '* @li Mass of the body.

  '* @li Position of the center of mass with respect to the point of reference.

  '* In the current implementation the center of mass and the point of

  '* reference must coincide.

  '* @li Inertia matrix. This is a 3x3 matrix that describes how the body's mass

  '* is distributed around the center of mass. Conceptually each body has an

  '* x-y-z coordinate frame embedded in it that moves and rotates with the body.

  '*

  '* The origin of this coordinate frame is the body's point of reference. Some values

  '* in ODE (vectors, matrices etc) are relative to the body coordinate frame, and others

  '* are relative to the global coordinate frame.

  '*

  '* Note that the shape of a rigid body is not a dynamical property (except insofar as

  '* it influences the various mass properties). It is only collision detection that cares

  '* about the detailed shape of the body.

  '*/





  '/**

  '* @brief Get auto disable linear average threshold.

  '* @ingroup bodies

  '* @return the threshold

  '*/

  DECLARE FUNCTION  dBodyGetAutoDisableLinearThreshold  LIB "ode.dll" ALIAS "dBodyGetAutoDisableLinearThreshold" (BYVAL dBodyIDlike AS dBodyID) AS dReal



  '/**

  '* @brief Set auto disable linear average threshold.

  '* @ingroup bodies

  '* @return the threshold

  '*/

  DECLARE SUB dBodySetAutoDisableLinearThreshold  LIB "ode.dll" ALIAS "dBodySetAutoDisableLinearThreshold" (BYVAL dBodyIDlike AS dBodyID, BYVAL linear_average_threshold AS dReal)



  '/**

  '* @brief Get auto disable angular average threshold.

  '* @ingroup bodies

  '* @return the threshold

  '*/

  DECLARE FUNCTION  dBodyGetAutoDisableAngularThreshold  LIB "ode.dll" ALIAS "dBodyGetAutoDisableAngularThreshold" (BYVAL dBodyIDlike AS dBodyID) AS dReal



  '/**

  '* @brief Set auto disable angular average threshold.

  '* @ingroup bodies

  '* @return the threshold

  '*/

  DECLARE SUB dBodySetAutoDisableAngularThreshold  LIB "ode.dll" ALIAS "dBodySetAutoDisableAngularThreshold" (BYVAL dBodyIDlike AS dBodyID, BYVAL angular_average_threshold AS dReal)



  '/**

  '* @brief Get auto disable average size (samples count).

  '* @ingroup bodies

  '* @return the nr of steps/size.

  '*/

  DECLARE FUNCTION  dBodyGetAutoDisableAverageSamplesCount  LIB "ode.dll" ALIAS "dBodyGetAutoDisableAverageSamplesCount" (BYVAL dBodyIDlike AS dBodyID) AS LONG



  '/**

  '* @brief Set auto disable average buffer size (average steps).

  '* @ingroup bodies

  '* @param average_samples_count the nr of samples to review.

  '*/

  DECLARE SUB dBodySetAutoDisableAverageSamplesCount  LIB "ode.dll" ALIAS "dBodySetAutoDisableAverageSamplesCount" (BYVAL dBodyIDlike AS dBodyID, BYVAL average_samples_count AS long)





  '/**

  '* @brief Get auto steps a body must be thought of as idle to disable

  '* @ingroup bodies

  '* @return the nr of steps

  '*/

  DECLARE FUNCTION  dBodyGetAutoDisableSteps  LIB "ode.dll" ALIAS "dBodyGetAutoDisableSteps" (BYVAL dBodyIDlike AS dBodyID) AS LONG



  '/**

  '* @brief Set auto disable steps.

  '* @ingroup bodies

  '* @param steps the nr of steps.

  '*/

  DECLARE SUB dBodySetAutoDisableSteps  LIB "ode.dll" ALIAS "dBodySetAutoDisableSteps" (BYVAL dBodyIDlike AS dBodyID, BYVAL steps AS LONG)



  '/**

  '* @brief Get auto disable time.

  '* @ingroup bodies

  '* @return nr of seconds

  '*/

  DECLARE FUNCTION  dBodyGetAutoDisableTime  LIB "ode.dll" ALIAS "dBodyGetAutoDisableTime" (BYVAL dBodyIDlike AS dBodyID) AS dReal



  '/**

  '* @brief Set auto disable time.

  '* @ingroup bodies

  '* @param time nr of seconds.

  '*/

  DECLARE SUB dBodySetAutoDisableTime  LIB "ode.dll" ALIAS "dBodySetAutoDisableTime" (BYVAL dBodyIDlike AS dBodyID, BYVAL time AS dReal)



  '/**

  '* @brief Get auto disable flag.

  '* @ingroup bodies

  '* @return 0 or 1

  '*/

  DECLARE FUNCTION  dBodyGetAutoDisableFlag  LIB "ode.dll" ALIAS "dBodyGetAutoDisableFlag" (BYVAL dBodyIDlike AS dBodyID) AS LONG



  '/**

  '* @brief Set auto disable flag.

  '* @ingroup bodies

  '* @param do_auto_disable 0 or 1

  '*/

  DECLARE SUB dBodySetAutoDisableFlag  LIB "ode.dll" ALIAS "dBodySetAutoDisableFlag" (BYVAL dBodyIDlike AS dBodyID, BYVAL do_auto_disable AS LONG)



  '/**

  '* @brief Set auto disable defaults.

  '* @remarks

  '* Set the values for the body to those set as default for the world.

  '* @ingroup bodies

  '*/

  DECLARE SUB dBodySetAutoDisableDefaults  LIB "ode.dll" ALIAS "dBodySetAutoDisableDefaults" (BYVAL dBodyIDlike AS dBodyID)





  '/**

  '* @brief Retrives the world attached to te given body.

  '* @remarks

  '*

  '* @ingroup bodies

  '*/

  DECLARE FUNCTION  dBodyGetWorld  LIB "ode.dll" ALIAS "dBodyGetWorld" (BYVAL dBodyIDlike AS dBodyID) AS dWorldID



  '/**

  '* @brief Create a body in given world.

  '* @remarks

  '* Default mass parameters are at position (0,0,0).

  '* @ingroup bodies

  '*/

  DECLARE FUNCTION  dBodyCreate  LIB "ode.dll" ALIAS "dBodyCreate" (BYVAL dWorldIDlike AS dWorldID) AS dBodyID



  '/**

  '* @brief Destroy a body.

  '* @remarks

  '* All joints that are attached to this body will be put into limbo:

  '* i.e. unattached and not affecting the simulation, but they will NOT be

  '* deleted.

  '* @ingroup bodies

  '*/

  DECLARE SUB dBodyDestroy  LIB "ode.dll" ALIAS "dBodyDestroy" (BYVAL dBodyIDlike AS dBodyID)



  '/**

  '* @brief Set the body's user-data pointer.

  '* @ingroup bodies

  '* @param data arbitraty pointer

  '*/

  DECLARE SUB dBodySetData  LIB "ode.dll" ALIAS "dBodySetData" (BYVAL dBodyIDlike AS dBodyID, BYREF data AS dword)



  '/**

  '* @brief Get the body's user-data pointer.

  '* @ingroup bodies

  '* @return a pointer to the user's data.

  '*/

  DECLARE FUNCTION dBodyGetData  LIB "ode.dll" ALIAS "dBodyGetData" (BYVAL dBodyIDlike AS dBodyID) as DWORD



  '/**

  '* @brief Set position of a body.

  '* @remarks

  '* After setting, the outcome of the simulation is undefined

  '* if the new configuration is inconsistent with the joints/constraints

  '* that are present.

  '* @ingroup bodies

  '*/

  DECLARE SUB dBodySetPosition  LIB "ode.dll" ALIAS "dBodySetPosition" (BYVAL dBodyIDlike AS dBodyID, BYVAL x AS dReal, BYVAL y AS dReal, BYVAL z AS dReal)



  '/**

  '* @brief Set the orientation of a body.

  '* @ingroup bodies

  '* @remarks

  '* After setting, the outcome of the simulation is undefined

  '* if the new configuration is inconsistent with the joints/constraints

  '* that are present.

  '*/

  DECLARE SUB dBodySetRotation  LIB "ode.dll" ALIAS "dBodySetRotation" (BYVAL dBodyIDlike AS dBodyID, BYVAL R() AS dReal)



  '/**

  '* @brief Set the orientation of a body.

  '* @ingroup bodies

  '* @remarks

  '* After setting, the outcome of the simulation is undefined

  '* if the new configuration is inconsistent with the joints/constraints

  '* that are present.

  '*/

  DECLARE SUB dBodySetQuaternion  LIB "ode.dll" ALIAS "dBodySetQuaternion" (BYVAL dBodyIDlike AS dBodyID, BYVAL q() AS dReal)



  '/**

  '* @brief Set the linear velocity of a body.

  '* @ingroup bodies

  '*/

  DECLARE SUB dBodySetLinearVel  LIB "ode.dll" ALIAS "dBodySetLinearVel" (BYVAL dBodyIDlike AS dBodyID, BYVAL x AS dReal, BYVAL y AS dReal, BYVAL z AS dReal)



  '/**

  '* @brief Set the angular velocity of a body.

  '* @ingroup bodies

  '*/

  DECLARE SUB dBodySetAngularVel  LIB "ode.dll" ALIAS "dBodySetAngularVel" (BYVAL dBodyIDlike AS dBodyID, BYVAL x AS dReal, BYVAL y AS dReal, BYVAL z AS dReal)



  '/**

  '* @brief Get the position of a body.

  '* @ingroup bodies

  '* @remarks

  '* When getting, the returned values are pointers to internal data structures,* so the vectors are valid until any changes are made to the rigid body



  '* system structure.

  '* @sa dBodyCopyPosition

  '*/

  DECLARE FUNCTION   dBodyGetPosition  LIB "ode.dll" ALIAS "dBodyGetPosition" (BYVAL dBodyIDlike AS dBodyID) AS dReal PTR





  '/**

  '* @brief Copy the position of a body into a vector.

  '* @ingroup bodies

  '* @param body the body to query

  '* @param pos a copy of the body position

  '* @sa dBodyGetPosition

  '*/

  DECLARE SUB dBodyCopyPosition  LIB "ode.dll" ALIAS "dBodyCopyPosition" (BYVAL body AS dBodyID, BYVAL pos() AS dReal)





  '/**

  '* @brief Get the rotation of a body.

  '* @ingroup bodies

  '* @return pointer to a 4x3 rotation matrix.

  '*/

  DECLARE FUNCTION   dBodyGetRotation  LIB "ode.dll" ALIAS "dBodyGetRotation" (BYVAL dBodyIDlike AS dBodyID) AS dword





  '/**

  '* @brief Copy the rotation of a body.

  '* @ingroup bodies

  '* @param body the body to query

  '* @param R a copy of the rotation matrix

  '* @sa dBodyGetRotation

  '*/

  DECLARE SUB dBodyCopyRotation  LIB "ode.dll" ALIAS "dBodyCopyRotation" (BYVAL dBodyIDlike AS dBodyID, BYVAL R() AS dReal)





  '/**

  '* @brief Get the rotation of a body.

  '* @ingroup bodies

  '* @return pointer to 4 scalars that represent the quaternion.

  '*/

  DECLARE FUNCTION   dBodyGetQuaternion  LIB "ode.dll" ALIAS "dBodyGetQuaternion" (BYVAL dBodyIDlike AS dBodyID) AS dword





  '/**

  '* @brief Copy the orientation of a body into a quaternion.

  '* @ingroup bodies

  '* @param body the body to query

  '* @param quat a copy of the orientation quaternion

  '* @sa dBodyGetQuaternion

  '*/

  DECLARE function dBodyCopyQuaternion LIB "ode.dll" ALIAS "dBodyCopyQuaternion" (BYVAL body AS dBodyID, BYVAL quat() AS dReal) as dword





  '/**

  '* @brief Get the linear velocity of a body.

  '* @ingroup bodies

  '*/

  DECLARE FUNCTION   dBodyGetLinearVel  LIB "ode.dll" ALIAS "dBodyGetLinearVel" (BYVAL dBodyIDlike AS dBodyID) AS dword



  '/**

  '* @brief Get the angular velocity of a body.

  '* @ingroup bodies

  '*/

  DECLARE FUNCTION   dBodyGetAngularVel  LIB "ode.dll" ALIAS "dBodyGetAngularVel" (BYVAL dBodyIDlike AS dBodyID) AS dword



  '/**

  '* @brief Set the mass of a body.

  '* @ingroup bodies

  '*/

  DECLARE SUB dBodySetMass  LIB "ode.dll" ALIAS "dBodySetMass" (BYVAL dBodyIDlike AS dBodyID, BYREF mass AS dMass)



  '/**

  '* @brief Get the mass of a body.

  '* @ingroup bodies

  '*/

  DECLARE SUB dBodyGetMass  LIB "ode.dll" ALIAS "dBodyGetMass" (BYVAL dBodyIDlike AS dBodyID, BYREF mass AS dMass)



  '/**

  '* @brief Add force at centre of mass of body in absolute coordinates.

  '* @ingroup bodies

  '*/

  DECLARE SUB dBodyAddForce  LIB "ode.dll" ALIAS "dBodyAddForce" (BYVAL dBodyIDlike AS dBodyID, BYVAL fx AS dReal, BYVAL fy AS dReal, BYVAL fz AS dReal)



  '/**

  '* @brief Add torque at centre of mass of body in absolute coordinates.

  '* @ingroup bodies

  '*/

  DECLARE SUB dBodyAddTorque  LIB "ode.dll" ALIAS "dBodyAddTorque" (BYVAL dBodyIDlike AS dBodyID, BYVAL fx AS dReal, BYVAL fy AS dReal, BYVAL fz AS dReal)



  '/**

  '* @brief Add force at centre of mass of body in coordinates relative to body.

  '* @ingroup bodies

  '*/

  DECLARE SUB dBodyAddRelForce  LIB "ode.dll" ALIAS "dBodyAddRelForce" (BYVAL dBodyIDlike AS dBodyID, BYVAL fx AS dReal, BYVAL fy AS dReal, BYVAL fz AS dReal)



  '/**

  '* @brief Add torque at centre of mass of body in coordinates relative to body.

  '* @ingroup bodies

  '*/

  DECLARE SUB dBodyAddRelTorque  LIB "ode.dll" ALIAS "dBodyAddRelTorque" (BYVAL dBodyIDlike AS dBodyID, BYVAL fx AS dReal, BYVAL fy AS dReal, BYVAL fz AS dReal)



  '/**

  '* @brief Add force at specified point in body in global coordinates.

  '* @ingroup bodies

  '*/

  DECLARE SUB dBodyAddForceAtPos  LIB "ode.dll" ALIAS "dBodyAddForceAtPos" (BYVAL dBodyIDlike AS dBodyID, BYVAL fx AS dReal, BYVAL fy AS dReal, BYVAL fz AS dReal, BYVAL px AS dReal, BYVAL py AS dReal, BYVAL pz AS dReal)



  '/**

  '* @brief Add force at specified point in body in local coordinates.

  '* @ingroup bodies

  '*/

  DECLARE SUB dBodyAddForceAtRelPos  LIB "ode.dll" ALIAS "dBodyAddForceAtRelPos" (BYVAL dBodyIDlike AS dBodyID, BYVAL fx AS dReal, BYVAL fy AS dReal, BYVAL fz AS dReal, BYVAL px AS dReal, BYVAL py AS dReal, BYVAL pz AS dReal)



  '/**

  '* @brief Add force at specified point in body in global coordinates.

  '* @ingroup bodies

  '*/

  DECLARE SUB dBodyAddRelForceAtPos  LIB "ode.dll" ALIAS "dBodyAddRelForceAtPos" (BYVAL dBodyIDlike AS dBodyID, BYVAL fx AS dReal, BYVAL fy AS dReal, BYVAL fz AS dReal, BYVAL px AS dReal, BYVAL py AS dReal, BYVAL pz AS dReal)



  '/**

  '* @brief Add force at specified point in body in local coordinates.

  '* @ingroup bodies

  '*/

  DECLARE SUB dBodyAddRelForceAtRelPos  LIB "ode.dll" ALIAS "dBodyAddRelForceAtRelPos" (BYVAL dBodyIDlike AS dBodyID, BYVAL fx AS dReal, BYVAL fy AS dReal, BYVAL fz AS dReal, BYVAL px AS dReal, BYVAL py AS dReal, BYVAL pz AS dReal)





  '/**

  '* @brief Return the current accumulated force vector.

  '* @return points to an array of 3 reals.

  '* @remarks

  '* The returned values are pointers to internal data structures, so

  '* the vectors are only valid until any changes are made to the rigid

  '* body system.

  '* @ingroup bodies

  '*/

  DECLARE FUNCTION   dBodyGetForce  LIB "ode.dll" ALIAS "dBodyGetForce" (BYVAL dBodyIDlike AS dBodyID) AS dword



  '/**

  '* @brief Return the current accumulated torque vector.

  '* @return points to an array of 3 reals.

  '* @remarks

  '* The returned values are pointers to internal data structures, so

  '* the vectors are only valid until any changes are made to the rigid

  '* body system.

  '* @ingroup bodies

  '*/

  DECLARE FUNCTION   dBodyGetTorque  LIB "ode.dll" ALIAS "dBodyGetTorque" (BYVAL dBodyIDlike AS dBodyID) AS dword



  '/**

  '* @brief Set the body force accumulation vector.

  '* @remarks

  '* This is mostly useful to zero the force and torque for deactivated bodies

  '* before they are reactivated, in the case where the force-adding functions

  '* were called on them while they were deactivated.

  '* @ingroup bodies

  '*/

  DECLARE SUB dBodySetForce  LIB "ode.dll" ALIAS "dBodySetForce" (BYVAL b AS dBodyID, BYVAL x AS dReal, BYVAL y AS dReal, BYVAL z AS dReal)



  '/**

  '* @brief Set the body torque accumulation vector.

  '* @remarks

  '* This is mostly useful to zero the force and torque for deactivated bodies

  '* before they are reactivated, in the case where the force-adding functions

  '* were called on them while they were deactivated.

  '* @ingroup bodies

  '*/

  DECLARE SUB dBodySetTorque  LIB "ode.dll" ALIAS "dBodySetTorque" (BYVAL b AS dBodyID, BYVAL x AS dReal, BYVAL y AS dReal, BYVAL z AS dReal)



  '/**

  '* @brief Get world position of a relative point on body.

  '* @ingroup bodies

  '* @param result will contain the result.

  '*/

  DECLARE SUB dBodyGetRelPointPos LIB "ode.dll" ALIAS "dBodyGetRelPointPos"  ( byval dBodyIDLike as dBodyID, byval px as dReal, byval py as dReal, byval pz as dReal, byval result() as dReal)



  '/**

  '* @brief Get velocity vector in global coords of a relative point on body.

  '* @ingroup bodies

  '* @param result will contain the result.

  '*/

  DECLARE SUB dBodyGetRelPointVel LIB "ode.dll" ALIAS "dBodyGetRelPointVel"  ( byval dBodyIDLike as dBodyID, byval px as dReal, byval py as dReal, byval pz as dReal, byval result() as dReal)



  '/**

  '* @brief Get velocity vector in global coords of a globally

  '* specified point on a body.

  '* @ingroup bodies

  '* @param result will contain the result.

  '*/

  DECLARE SUB dBodyGetPointVel LIB "ode.dll" ALIAS "dBodyGetPointVel"  ( byval dBodyIDLike as dBodyID, byval px as dReal, byval py as dReal, byval pz as dReal, byval result() as dReal)



  '/**

  '* @brief takes a point in global coordinates and returns

  '* the point's position in body-relative coordinates.

  '* @remarks

  '* This is the inverse of dBodyGetRelPointPos()

  '* @ingroup bodies

  '* @param result will contain the result.

  '*/

  DECLARE SUB dBodyGetPosRelPoint LIB "ode.dll" ALIAS "dBodyGetPosRelPoint"  ( byval dBodyIDLike as dBodyID, byval px as dReal, byval py as dReal, byval pz as dReal, byval result() as dReal)




  '/**

  '* @brief Convert from local to world coordinates.

  '* @ingroup bodies

  '* @param result will contain the result.

  '*/

  DECLARE SUB dBodyVectorToWorld LIB  "ode.dll" ALIAS "dBodyVectorToWorld"  ( byval dBodyIDLike as dBodyID, byval px as dReal, byval py as dReal, byval pz as dReal, byval result() as dReal)





  '/**

  '* @brief Convert from world to local coordinates.

  '* @ingroup bodies

  '* @param result will contain the result.

  '*/

  DECLARE SUB dBodyVectorFromWorld LIB "ode.dll" ALIAS "dBodyVectorFromWorld"  ( byval dBodyIDLike as dBodyID, byval px as dReal, byval py as dReal, byval pz as dReal, byval result() as dReal)




  '/**

  '* @brief controls the way a body's orientation is updated at each timestep.

  '* @ingroup bodies

  '* @param mode can be 0 or 1:

  '* \li 0: An ``infinitesimal'' orientation update is used.

  '* This is fast to compute, but it can occasionally cause inaccuracies

  '* for bodies that are rotating at high speed, especially when those

  '* bodies are joined to other bodies.

  '* This is the default for every new body that is created.

  '* \li 1: A ``finite'' orientation update is used.

  '* This is more costly to compute, but will be more accurate for high

  '* speed rotations.

  '* @remarks

  '* Note however that high speed rotations can result in many types of

  '* error in a simulation, and the finite mode will only fix one of those

  '* sources of error.

  '*/

  DECLARE SUB dBodySetFiniteRotationMode  LIB "ode.dll" ALIAS "dBodySetFiniteRotationMode" (BYVAL dBodyIDlike AS dBodyID, BYVAL mode AS LONG)



  '/**

  '* @brief sets the finite rotation axis for a body.

  '* @ingroup bodies

  '* @remarks

  '* This is axis only has meaning when the finite rotation mode is set

  '* If this axis is zero (0,0,0), full finite rotations are performed on

  '* the body.

  '* If this axis is nonzero, the body is rotated by performing a partial finite

  '* rotation along the axis direction followed by an infinitesimal rotation

  '* along an orthogonal direction.

  '* @remarks

  '* This can be useful to alleviate certain sources of error caused by quickly

  '* spinning bodies. For example, if a car wheel is rotating at high speed

  '* you can call this function with the wheel's hinge axis as the argument to

  '* try and improve its behavior.

  '*/

  DECLARE SUB dBodySetFiniteRotationAxis  LIB "ode.dll" ALIAS "dBodySetFiniteRotationAxis" (BYVAL dBodyIDlike AS dBodyID, BYVAL x AS dReal, BYVAL y AS dReal, BYVAL z AS dReal)



  '/**

  '* @brief Get the way a body's orientation is updated each timestep.

  '* @ingroup bodies

  '* @return the mode 0 (infitesimal) or 1 (finite).

  '*/

  DECLARE FUNCTION  dBodyGetFiniteRotationMode  LIB "ode.dll" ALIAS "dBodyGetFiniteRotationMode" (BYVAL dBodyIDlike AS dBodyID) AS LONG



  '/**

  '* @brief Get the finite rotation axis.

  '* @param result will contain the axis.

  '* @ingroup bodies

  '*/

  DECLARE SUB dBodyGetFiniteRotationAxis  LIB "ode.dll" ALIAS "dBodyGetFiniteRotationAxis" (BYVAL dBodyIDlike AS dBodyID, BYVAL result() AS dReal)



  '/**

  '* @brief Get the number of joints that are attached to this body.

  '* @ingroup bodies

  '* @return nr of joints

  '*/

  DECLARE FUNCTION  dBodyGetNumJoints  LIB "ode.dll" ALIAS "dBodyGetNumJoints" (BYVAL b AS dBodyID) AS LONG



  '/**

  '* @brief Return a joint attached to this body, given by index.

  '* @ingroup bodies

  '* @param index valid range is 0 to n-1 where n is the value returned by

  '* dBodyGetNumJoints().

  '*/

  DECLARE FUNCTION  dBodyGetJoint  LIB "ode.dll" ALIAS "dBodyGetJoint" (BYVAL dBodyIDlike AS dBodyID, BYVAL index AS LONG) AS dJointID



  '/**

  '* @brief Manually enable a body.

  '* @param dBodyID identification of body.

  '* @ingroup bodies

  '*/

  DECLARE SUB dBodyEnable  LIB "ode.dll" ALIAS "dBodyEnable" (BYVAL dBodyIDlike AS dBodyID)



  '/**

  '* @brief Manually disable a body.

  '* @ingroup bodies

  '* @remarks

  '* A disabled body that is connected through a joint to an enabled body will

  '* be automatically re-enabled at the next simulation step.

  '*/

  DECLARE SUB dBodyDisable  LIB "ode.dll" ALIAS "dBodyDisable" (BYVAL dBodyIDlike AS dBodyID)



  '/**

  '* @brief Check wether a body is enabled.

  '* @ingroup bodies

  '* @return 1 if a body is currently enabled or 0 if it is disabled.

  '*/

  DECLARE FUNCTION  dBodyIsEnabled  LIB "ode.dll" ALIAS "dBodyIsEnabled" (BYVAL dBodyIDlike AS dBodyID) AS LONG



  '/**

  '* @brief Set whether the body is influenced by the world's gravity or not.

  '* @ingroup bodies

  '* @param mode when nonzero gravity affects this body.

  '* @remarks

  '* Newly created bodies are always influenced by the world's gravity.

  '*/

  DECLARE SUB dBodySetGravityMode  LIB "ode.dll" ALIAS "dBodySetGravityMode" (BYVAL b AS dBodyID, BYVAL mode AS LONG)



  '/**

  '* @brief Get whether the body is influenced by the world's gravity or not.

  '* @ingroup bodies

  '* @return nonzero means gravity affects this body.

  '*/

  DECLARE FUNCTION  dBodyGetGravityMode  LIB "ode.dll" ALIAS "dBodyGetGravityMode" (BYVAL b AS dBodyID) AS LONG







  '/**

  '* @defgroup joints Joints

  '*

  '* In real life a joint is something like a hinge, that is used to connect two

  '* objects.

  '* In ODE a joint is very similar: It is a relationship that is enforced between

  '* two bodies so that they can only have certain positions and orientations

  '* relative to each other.

  '* This relationship is called a constraint -- the words joint and

  '* constraint are often used interchangeably.

  '*

  '* A joint has a set of parameters that can be set. These include:

  '*

  '*

  '* \li dParamLoStop Low stop angle or position. Setting this to

  '*  -dInfinity (the default value) turns off the low stop.

  '*  For rotational joints, this stop must be greater than -pi to be

  '*  effective.

  '* \li dParamHiStop High stop angle or position. Setting this to

  '*  dInfinity (the default value) turns off the high stop.

  '*  For rotational joints, this stop must be less than pi to be

  '*  effective.

  '*  If the high stop is less than the low stop then both stops will

  '*  be ineffective.

  '* \li dParamVel Desired motor velocity (this will be an angular or

  '*  linear velocity).

  '* \li dParamFMax The maximum force or torque that the motor will use to

  '*  achieve the desired velocity.

  '*  This must always be greater than or equal to zero.

  '*  Setting this to zero (the default value) turns off the motor.

  '* \li dParamFudgeFactor The current joint stop/motor implementation has

  '*  a small problem:

  '*  when the joint is at one stop and the motor is set to move it away

  '*  from the stop, too much force may be applied for one time step,*  causing a ``jumping'' motion.



  '*  This fudge factor is used to scale this excess force.

  '*  It should have a value between zero and one (the default value).

  '*  If the jumping motion is too visible in a joint, the value can be

  '*  reduced.

  '*  Making this value too small can prevent the motor from being able to

  '*  move the joint away from a stop.

  '* \li dParamBounce The bouncyness of the stops.

  '*  This is a restitution parameter in the range 0..1.

  '*  0 means the stops are not bouncy at all, 1 means maximum bouncyness.

  '* \li dParamCFM The constraint force mixing (CFM) value used when not

  '*  at a stop.

  '* \li dParamStopERP The error reduction parameter (ERP) used by the

  '*  stops.

  '* \li dParamStopCFM The constraint force mixing (CFM) value used by the

  '*  stops. Together with the ERP value this can be used to get spongy or

  '*  soft stops.

  '*  Note that this is intended for unpowered joints, it does not really

  '*  work as expected when a powered joint reaches its limit.

  '* \li dParamSuspensionERP Suspension error reduction parameter (ERP).

  '*  Currently this is only implemented on the hinge-2 joint.

  '* \li dParamSuspensionCFM Suspension constraint force mixing (CFM) value.

  '*  Currently this is only implemented on the hinge-2 joint.

  '*

  '* If a particular parameter is not implemented by a given joint, setting it

  '* will have no effect.

  '* These parameter names can be optionally followed by a digit (2 or 3)

  '* to indicate the second or third set of parameters, e.g. for the second axis

  '* in a hinge-2 joint, or the third axis in an AMotor joint.

  '*/





  '/**

  '* @brief Create a new joint of the ball type.

  '* @ingroup joints

  '* @remarks

  '* The joint is initially in "limbo" (i.e. it has no effect on the simulation)

  '* because it does not connect to any bodies.

  '* @param dJointGroupID set to 0 to allocate the joint normally.

  '* If it is nonzero the joint is allocated in the given joint group.

  '*/

  DECLARE FUNCTION  dJointCreateBall  LIB "ode.dll" ALIAS "dJointCreateBall" (BYVAL dWorldIDlike AS dWorldID, BYVAL dJointGroup AS dJointGroupID) AS dJointID



  '/**

  '* @brief Create a new joint of the hinge type.

  '* @ingroup joints

  '* @param dJointGroupID set to 0 to allocate the joint normally.

  '* If it is nonzero the joint is allocated in the given joint group.

  '*/

  DECLARE FUNCTION  dJointCreateHinge  LIB "ode.dll" ALIAS "dJointCreateHinge" (BYVAL dWorldIDlike AS dWorldID, BYVAL dJointGroup AS dJointGroupID) AS dJointID



  '/**

  '* @brief Create a new joint of the slider type.

  '* @ingroup joints

  '* @param dJointGroupID set to 0 to allocate the joint normally.

  '* If it is nonzero the joint is allocated in the given joint group.

  '*/

  DECLARE FUNCTION  dJointCreateSlider  LIB "ode.dll" ALIAS "dJointCreateSlider" (BYVAL dWorldIDlike AS dWorldID, BYVAL dJointGroup AS dJointGroupID) AS dJointID



  '/**

  '* @brief Create a new joint of the contact type.

  '* @ingroup joints

  '* @param dJointGroupID set to 0 to allocate the joint normally.

  '* If it is nonzero the joint is allocated in the given joint group.

  '*/

  DECLARE FUNCTION  dJointCreateContact  LIB "ode.dll" ALIAS "dJointCreateContact" (BYVAL dWorldIDlike AS dWorldID, BYVAL dJointGroup AS dJointGroupID, BYREF dContactID AS dContact) AS dJointID



  '/**

  '* @brief Create a new joint of the hinge2 type.

  '* @ingroup joints

  '* @param dJointGroupID set to 0 to allocate the joint normally.

  '* If it is nonzero the joint is allocated in the given joint group.

  '*/

  DECLARE FUNCTION  dJointCreateHinge2  LIB "ode.dll" ALIAS "dJointCreateHinge2" (BYVAL dWorldIDlike AS dWorldID, BYVAL dJointGroup AS dJointGroupID) AS dJointID



  '/**

  '* @brief Create a new joint of the universal type.

  '* @ingroup joints

  '* @param dJointGroupID set to 0 to allocate the joint normally.

  '* If it is nonzero the joint is allocated in the given joint group.

  '*/

  DECLARE FUNCTION  dJointCreateUniversal  LIB "ode.dll" ALIAS "dJointCreateUniversal" (BYVAL dWorldIDlike AS dWorldID, BYVAL dJointGroup AS dJointGroupID) AS dJointID



  '/**

  '* @brief Create a new joint of the PR (Prismatic and Rotoide) type.

  '* @ingroup joints

  '* @param dJointGroupID set to 0 to allocate the joint normally.

  '* If it is nonzero the joint is allocated in the given joint group.

  '*/

  DECLARE FUNCTION  dJointCreatePR  LIB "ode.dll" ALIAS "dJointCreatePR" (BYVAL dWorldIDlike AS dWorldID, BYVAL dJointGroup AS dJointGroupID) AS dJointID



  '/**

  '* @brief Create a new joint of the fixed type.

  '* @ingroup joints

  '* @param dJointGroupID set to 0 to allocate the joint normally.

  '* If it is nonzero the joint is allocated in the given joint group.

  '*/

  DECLARE FUNCTION  dJointCreateFixed  LIB "ode.dll" ALIAS "dJointCreateFixed" (BYVAL dWorldIDlike AS dWorldID, BYVAL dJointGroup AS dJointGroupID) AS dJointID



  DECLARE FUNCTION  dJointCreateNull  LIB "ode.dll" ALIAS "dJointCreateNull" (BYVAL dWorldIDlike AS dWorldID, BYVAL dJointGroup AS dJointGroupID) AS dJointID



  '/**

  '* @brief Create a new joint of the A-motor type.

  '* @ingroup joints

  '* @param dJointGroupID set to 0 to allocate the joint normally.

  '* If it is nonzero the joint is allocated in the given joint group.

  '*/

  DECLARE FUNCTION  dJointCreateAMotor  LIB "ode.dll" ALIAS "dJointCreateAMotor" (BYVAL dWorldIDlike AS dWorldID, BYVAL dJointGroup AS dJointGroupID) AS dJointID



  '/**

  '* @brief Create a new joint of the L-motor type.

  '* @ingroup joints

  '* @param dJointGroupID set to 0 to allocate the joint normally.

  '* If it is nonzero the joint is allocated in the given joint group.

  '*/

  DECLARE FUNCTION  dJointCreateLMotor  LIB "ode.dll" ALIAS "dJointCreateLMotor" (BYVAL dWorldIDlike AS dWorldID, BYVAL dJointGroup AS dJointGroupID) AS dJointID



  '/**

  '* @brief Create a new joint of the plane-2d type.

  '* @ingroup joints

  '* @param dJointGroupID set to 0 to allocate the joint normally.

  '* If it is nonzero the joint is allocated in the given joint group.

  '*/

  DECLARE FUNCTION  dJointCreatePlane2D  LIB "ode.dll" ALIAS "dJointCreatePlane2D" (BYVAL dWorldIDlike AS dWorldID, BYVAL dJointGroup AS dJointGroupID) AS dJointID



  '/**

  '* @brief Destroy a joint.

  '* @ingroup joints

  '*

  '* disconnects it from its attached bodies and removing it from the world.

  '* However, if the joint is a member of a group then this function has no

  '* effect - to destroy that joint the group must be emptied or destroyed.

  '*/

  DECLARE SUB dJointDestroy  LIB "ode.dll" ALIAS "dJointDestroy" (BYVAL dJointIDlike AS dJointID)





  '/**

  '* @brief Create a joint group

  '* @ingroup joints

  '* @param max_size deprecated. Set to 0.

  '*/

  DECLARE FUNCTION  dJointGroupCreate  LIB "ode.dll" ALIAS "dJointGroupCreate" (BYVAL max_size AS LONG) AS dJointGroupID



  '/**

  '* @brief Destroy a joint group.

  '* @ingroup joints

  '*

  '* All joints in the joint group will be destroyed.

  '*/

  DECLARE SUB dJointGroupDestroy  LIB "ode.dll" ALIAS "dJointGroupDestroy" (BYVAL dJointGroup AS dJointGroupID)



  '/**

  '* @brief Empty a joint group.

  '* @ingroup joints

  '*

  '* All joints in the joint group will be destroyed,* but the joint group itself will not be destroyed.



  '*/

  DECLARE SUB dJointGroupEmpty  LIB "ode.dll" ALIAS "dJointGroupEmpty" (BYVAL dJointGroup AS dJointGroupID)



  '/**

  '* @brief Attach the joint to some new bodies.

  '* @ingroup joints

  '*

  '* If the joint is already attached, it will be detached from the old bodies

  '* first.

  '* To attach this joint to only one body, set body1 or body2 to zero - a zero

  '* body refers to the static environment.

  '* Setting both bodies to zero puts the joint into "limbo", i.e. it will

  '* have no effect on the simulation.

  '* @remarks

  '* Some joints, like hinge-2 need to be attached to two bodies to work.

  '*/

  DECLARE SUB dJointAttach  LIB "ode.dll" ALIAS "dJointAttach" (BYVAL dJointIDlike AS dJointID, BYVAL body1 AS dBodyID, BYVAL body2 AS dBodyID)



  '/**

  '* @brief Set the user-data pointer

  '* @ingroup joints

  '*/

  DECLARE SUB dJointSetData  LIB "ode.dll" ALIAS "dJointSetData" (BYVAL dJointIDlike AS dJointID, BYREF data as DWORD)



  '/**

  '* @brief Get the user-data pointer

  '* @ingroup joints

  '*/

  DECLARE function dJointGetData  LIB "ode.dll" ALIAS "dJointGetData" (BYVAL dJointIDlike AS dJointID) as dword



  '/**

  '* @brief Get the type of the joint

  '* @ingroup joints

  '* @return the type, being one of these:

  '* \li JointTypeBall

  '* \li JointTypeHinge

  '* \li JointTypeSlider

  '* \li JointTypeContact

  '* \li JointTypeUniversal

  '* \li JointTypeHinge2

  '* \li JointTypeFixed

  '* \li JointTypeAMotor

  '* \li JointTypeLMotor

  '*/

  DECLARE FUNCTION  dJointGetType  LIB "ode.dll" ALIAS "dJointGetType" (BYVAL dJointIDlike AS dJointID) AS LONG



  '/**

  '* @brief Return the bodies that this joint connects.

  '* @ingroup joints

  '* @param index return the first (0) or second (1) body.

  '* @remarks

  '* If one of these returned body IDs is zero, the joint connects the other body

  '* to the static environment.

  '* If both body IDs are zero, the joint is in ``limbo'' and has no effect on

  '* the simulation.

  '*/

  DECLARE FUNCTION  dJointGetBody  LIB "ode.dll" ALIAS "dJointGetBody" (BYVAL dJointIDlike AS dJointID, BYVAL index AS LONG) AS dword



  '/**

  '* @brief Sets the datastructure that is to receive the feedback.

  '*

  '* The feedback can be used by the user, so that it is known how

  '* much force an individual joint exerts.

  '* @ingroup joints

  '*/

  DECLARE function dJointSetFeedback  LIB "ode.dll" ALIAS "dJointSetFeedback" (BYVAL dJointIDlike AS dJointID, BYref dJointFeedbacklike as dJointFeedbackID) as dword



  '/**

  '* @brief Gets the datastructure that is to receive the feedback.

  '* @ingroup joints

  '*/

  DECLARE FUNCTION  dJointGetFeedback  LIB "ode.dll" ALIAS "dJointGetFeedback" (BYVAL dJointIDlike AS dJointID) AS dJointFeedback



  '/**

  '* @brief Set the joint anchor point.

  '* @ingroup joints

  '*

  '* The joint will try to keep this point on each body

  '* together. The input is specified in world coordinates.

  '*/

  DECLARE SUB dJointSetBallAnchor  LIB "ode.dll" ALIAS "dJointSetBallAnchor" (BYVAL dJointIDlike AS dJointID, BYVAL x AS dReal, BYVAL y AS dReal, BYVAL z AS dReal)



  '/**

  '* @brief Set the joint anchor point.

  '* @ingroup joints

  '*/

  DECLARE SUB dJointSetBallAnchor2  LIB "ode.dll" ALIAS "dJointSetBallAnchor2" (BYVAL dJointIDlike AS dJointID, BYVAL x AS dReal, BYVAL y AS dReal, BYVAL z AS dReal)



  '/**

  '* @brief Set hinge anchor parameter.

  '* @ingroup joints

  '*/

  DECLARE SUB dJointSetHingeAnchor  LIB "ode.dll" ALIAS "dJointSetHingeAnchor" (BYVAL dJointIDlike AS dJointID, BYVAL x AS dReal, BYVAL y AS dReal, BYVAL z AS dReal)



  DECLARE SUB dJointSetHingeAnchorDelta  LIB "ode.dll" ALIAS "dJointSetHingeAnchorDelta" (BYVAL dJointIDlike AS dJointID, BYVAL x AS dReal, BYVAL y AS dReal, BYVAL z AS dReal, BYVAL ax AS dReal, BYVAL ay AS dReal, BYVAL az AS dReal)



  '/**

  '* @brief Set hinge axis.

  '* @ingroup joints

  '*/

  DECLARE SUB dJointSetHingeAxis  LIB "ode.dll" ALIAS "dJointSetHingeAxis" (BYVAL dJointIDlike AS dJointID, BYVAL x AS dReal, BYVAL y AS dReal, BYVAL z AS dReal)



  '/**

  '* @brief set joint parameter

  '* @ingroup joints

  '*/

  DECLARE SUB dJointSetHingeParam  LIB "ode.dll" ALIAS "dJointSetHingeParam" (BYVAL dJointIDlike AS dJointID, BYVAL parameter AS LONG, BYVAL value AS dReal)



  '/**

  '* @brief Applies the torque about the hinge axis.

  '*

  '* That is, it applies a torque with specified magnitude in the direction

  '* of the hinge axis, to body 1, and with the same magnitude but in opposite

  '* direction to body 2. This function is just a wrapper for dBodyAddTorque()}

  '* @ingroup joints

  '*/

  DECLARE SUB dJointAddHingeTorque LIB "ode.dll" ALIAS "dJointAddHingeTorque" (BYVAL joint AS dJointID, BYVAL torque AS dReal)



  '/**

  '* @brief set the joint axis

  '* @ingroup joints

  '*/

  DECLARE SUB dJointSetSliderAxis  LIB "ode.dll" ALIAS "dJointSetSliderAxis" (BYVAL dJointIDlike AS dJointID, BYVAL x AS dReal, BYVAL y AS dReal, BYVAL z AS dReal)



  '/**

  '* @ingroup joints

  '*/

  DECLARE SUB dJointSetSliderAxisDelta  LIB "ode.dll" ALIAS "dJointSetSliderAxisDelta" (BYVAL dJointIDlike AS dJointID, BYVAL x AS dReal, BYVAL y AS dReal, BYVAL z AS dReal, BYVAL ax AS dReal, BYVAL ay AS dReal, BYVAL az AS dReal)



  '/**

  '* @brief set joint parameter

  '* @ingroup joints

  '*/

  DECLARE SUB dJointSetSliderParam  LIB "ode.dll" ALIAS "dJointSetSliderParam" (BYVAL dJointIDlike AS dJointID, BYVAL parameter AS LONG, BYVAL value AS dReal)



  '/**

  '* @brief Applies the given force in the slider's direction.

  '*

  '* That is, it applies a force with specified magnitude, in the direction of

  '* slider's axis, to body1, and with the same magnitude but opposite

  '* direction to body2. This function is just a wrapper for dBodyAddForce().

  '* @ingroup joints

  '*/

  DECLARE SUB dJointAddSliderForce LIB "ode.dll" ALIAS "dJointAddSliderForce" (BYVAL joint AS dJointID, BYVAL force AS dReal)



  '/**

  '* @brief set anchor

  '* @ingroup joints

  '*/

  DECLARE SUB dJointSetHinge2Anchor  LIB "ode.dll" ALIAS "dJointSetHinge2Anchor" (BYVAL dJointIDlike AS dJointID, BYVAL x AS dReal, BYVAL y AS dReal, BYVAL z AS dReal)



  '/**

  '* @brief set axis

  '* @ingroup joints

  '*/

  DECLARE SUB dJointSetHinge2Axis1  LIB "ode.dll" ALIAS "dJointSetHinge2Axis1" (BYVAL dJointIDlike AS dJointID, BYVAL x AS dReal, BYVAL y AS dReal, BYVAL z AS dReal)



  '/**

  '* @brief set axis

  '* @ingroup joints

  '*/

  DECLARE SUB dJointSetHinge2Axis2  LIB "ode.dll" ALIAS "dJointSetHinge2Axis2" (BYVAL dJointIDlike AS dJointID, BYVAL x AS dReal, BYVAL y AS dReal, BYVAL z AS dReal)



  '/**

  '* @brief set joint parameter

  '* @ingroup joints

  '*/

  DECLARE SUB dJointSetHinge2Param  LIB "ode.dll" ALIAS "dJointSetHinge2Param" (BYVAL dJointIDlike AS dJointID, BYVAL parameter AS LONG, BYVAL value AS dReal)



  '/**

  '* @brief Applies torque1 about the hinge2's axis 1, torque2 about the

  '* hinge2's axis 2.

  '* @remarks This function is just a wrapper for dBodyAddTorque().

  '* @ingroup joints

  '*/

  DECLARE SUB dJointAddHinge2Torques LIB "ode.dll" ALIAS "dJointAddHinge2Torques" (BYVAL joint AS dJointID, BYVAL torque1 AS dReal, BYVAL torque2 AS dReal)



  '/**

  '* @brief set anchor

  '* @ingroup joints

  '*/

  DECLARE SUB dJointSetUniversalAnchor  LIB "ode.dll" ALIAS "dJointSetUniversalAnchor" (BYVAL dJointIDlike AS dJointID, BYVAL x AS dReal, BYVAL y AS dReal, BYVAL z AS dReal)



  '/**

  '* @brief set axis

  '* @ingroup joints

  '*/

  DECLARE SUB dJointSetUniversalAxis1  LIB "ode.dll" ALIAS "dJointSetUniversalAxis1" (BYVAL dJointIDlike AS dJointID, BYVAL x AS dReal, BYVAL y AS dReal, BYVAL z AS dReal)



  '/**

  '* @brief set axis

  '* @ingroup joints

  '*/

  DECLARE SUB dJointSetUniversalAxis2  LIB "ode.dll" ALIAS "dJointSetUniversalAxis2" (BYVAL dJointIDlike AS dJointID, BYVAL x AS dReal, BYVAL y AS dReal, BYVAL z AS dReal)



  '/**

  '* @brief set joint parameter

  '* @ingroup joints

  '*/

  DECLARE SUB dJointSetUniversalParam  LIB "ode.dll" ALIAS "dJointSetUniversalParam" (BYVAL dJointIDlike AS dJointID, BYVAL parameter AS LONG, BYVAL value AS dReal)



  '/**

  '* @brief Applies torque1 about the universal's axis 1, torque2 about the

  '* universal's axis 2.

  '* @remarks This function is just a wrapper for dBodyAddTorque().

  '* @ingroup joints

  '*/

  DECLARE SUB dJointAddUniversalTorques LIB "ode.dll" ALIAS "dJointAddUniversalTorques" (BYVAL joint AS dJointID, BYVAL torque1 AS dReal, BYVAL torque2 AS dReal)





  '/**

  '* @brief set anchor

  '* @ingroup joints

  '*/

  DECLARE SUB dJointSetPRAnchor  LIB "ode.dll" ALIAS "dJointSetPRAnchor" (BYVAL dJointIDlike AS dJointID, BYVAL x AS dReal, BYVAL y AS dReal, BYVAL z AS dReal)



  '/**

  '* @brief set the axis for the prismatic articulation

  '* @ingroup joints

  '*/

  DECLARE SUB dJointSetPRAxis1  LIB "ode.dll" ALIAS "dJointSetPRAxis1" (BYVAL dJointIDlike AS dJointID, BYVAL x AS dReal, BYVAL y AS dReal, BYVAL z AS dReal)



  '/**

  '* @brief set the axis for the rotoide articulation

  '* @ingroup joints

  '*/

  DECLARE SUB dJointSetPRAxis2  LIB "ode.dll" ALIAS "dJointSetPRAxis2" (BYVAL dJointIDlike AS dJointID, BYVAL x AS dReal, BYVAL y AS dReal, BYVAL z AS dReal)



  '/**

  '* @brief set joint parameter

  '* @ingroup joints

  '*

  '* @note parameterX where X equal 2 refer to parameter for the rotoide articulation

  '*/

  DECLARE SUB dJointSetPRParam  LIB "ode.dll" ALIAS "dJointSetPRParam" (BYVAL dJointIDlike AS dJointID, BYVAL parameter AS LONG, BYVAL value AS dReal)



  '/**

  '* @brief Applies the torque about the rotoide axis of the PR joint

  '*

  '* That is, it applies a torque with specified magnitude in the direction

  '* of the rotoide axis, to body 1, and with the same magnitude but in opposite

  '* direction to body 2. This function is just a wrapper for dBodyAddTorque()}

  '* @ingroup joints

  '*/

  DECLARE SUB dJointAddPRTorque  LIB "ode.dll" ALIAS "dJointAddPRTorque" (BYVAL j AS dJointID, BYVAL torque AS dReal)





  '/**

  '* @brief Call this on the fixed joint after it has been attached to

  '* remember the current desired relative offset and desired relative

  '* rotation between the bodies.

  '* @ingroup joints

  '*/

  DECLARE SUB dJointSetFixed  LIB "ode.dll" ALIAS "dJointSetFixed" (BYVAL dJointIDlike AS dJointID)



  '/**

  '* @brief set the nr of axes

  '* @param num 0..3

  '* @ingroup joints

  '*/

  DECLARE SUB dJointSetAMotorNumAxes  LIB "ode.dll" ALIAS "dJointSetAMotorNumAxes" (BYVAL dJointIDlike AS dJointID, BYVAL num AS LONG)



  '/**

  '* @brief set axis

  '* @ingroup joints

  '*/

  DECLARE SUB dJointSetAMotorAxis  LIB "ode.dll" ALIAS "dJointSetAMotorAxis" (BYVAL dJointIDlike AS dJointID, BYVAL anum AS LONG, BYVAL rel AS LONG, BYVAL x AS dReal, BYVAL y AS dReal, BYVAL z AS dReal)





  '/**

  '* @brief Tell the AMotor what the current angle is along axis anum.

  '*

  '* This function should only be called in dAMotorUser mode, because in this

  '* mode the AMotor has no other way of knowing the joint angles.

  '* The angle information is needed if stops have been set along the axis,* but it is not needed for axis motors.



  '* @ingroup joints

  '*/

  DECLARE SUB dJointSetAMotorAngle  LIB "ode.dll" ALIAS "dJointSetAMotorAngle" (BYVAL dJointIDlike AS dJointID, BYVAL anum AS LONG, BYVAL angle AS dReal)



  '/**

  '* @brief set joint parameter

  '* @ingroup joints

  '*/

  DECLARE SUB dJointSetAMotorParam  LIB "ode.dll" ALIAS "dJointSetAMotorParam" (BYVAL dJointIDlike AS dJointID, BYVAL parameter AS LONG, BYVAL value AS dReal)



  '/**

  '* @brief set mode

  '* @ingroup joints

  '*/

  DECLARE SUB dJointSetAMotorMode  LIB "ode.dll" ALIAS "dJointSetAMotorMode" (BYVAL dJointIDlike AS dJointID, BYVAL mode AS LONG)



  '/**

  '* @brief Applies torque0 about the AMotor's axis 0, torque1 about the

  '* AMotor's axis 1, and torque2 about the AMotor's axis 2.

  '* @remarks

  '* If the motor has fewer than three axes, the higher torques are ignored.

  '* This function is just a wrapper for dBodyAddTorque().

  '* @ingroup joints

  '*/

  DECLARE SUB dJointAddAMotorTorques  LIB "ode.dll" ALIAS "dJointAddAMotorTorques" (BYVAL dJointIDlike AS dJointID, BYVAL torque1 AS dReal, BYVAL torque2 AS dReal, BYVAL torque3 AS dReal)



  '/**

  '* @brief Set the number of axes that will be controlled by the LMotor.

  '* @param num can range from 0 (which effectively deactivates the joint) to 3.

  '* @ingroup joints

  '*/

  DECLARE SUB dJointSetLMotorNumAxes  LIB "ode.dll" ALIAS "dJointSetLMotorNumAxes" (BYVAL dJointIDlike AS dJointID, BYVAL num AS LONG)



  '/**

  '* @brief Set the AMotor axes.

  '* @param anum selects the axis to change (0,1 or 2).

  '* @param rel Each axis can have one of three ``relative orientation'' modes

  '* \li 0: The axis is anchored to the global frame.

  '* \li 1: The axis is anchored to the first body.

  '* \li 2: The axis is anchored to the second body.

  '* @remarks The axis vector is always specified in global coordinates

  '* regardless of the setting of rel.

  '* @ingroup joints

  '*/

  DECLARE SUB dJointSetLMotorAxis  LIB "ode.dll" ALIAS "dJointSetLMotorAxis" (BYVAL dJointIDlike AS dJointID, BYVAL anum AS LONG, BYVAL rel AS LONG, BYVAL x AS dReal, BYVAL y AS dReal, BYVAL z AS dReal)



  '/**

  '* @brief set joint parameter

  '* @ingroup joints

  '*/

  DECLARE SUB dJointSetLMotorParam  LIB "ode.dll" ALIAS "dJointSetLMotorParam" (BYVAL dJointIDlike AS dJointID, BYVAL parameter AS LONG, BYVAL value AS dReal)



  '/**

  '* @ingroup joints

  '*/

  DECLARE SUB dJointSetPlane2DXParam  LIB "ode.dll" ALIAS "dJointSetPlane2DXParam" (BYVAL dJointIDlike AS dJointID, BYVAL parameter AS LONG, BYVAL value AS dReal)



  '/**

  '* @ingroup joints

  '*/



  DECLARE SUB dJointSetPlane2DYParam  LIB "ode.dll" ALIAS "dJointSetPlane2DYParam" (BYVAL dJointIDlike AS dJointID, BYVAL parameter AS LONG, BYVAL value AS dReal)



  '/**

  '* @ingroup joints

  '*/

  DECLARE SUB dJointSetPlane2DAngleParam  LIB "ode.dll" ALIAS "dJointSetPlane2DAngleParam" (BYVAL dJointIDlike AS dJointID, BYVAL parameter AS LONG, BYVAL value AS dReal)



  '/**

  '* @brief Get the joint anchor point, in world coordinates.

  '*

  '* This returns the point on body 1. If the joint is perfectly satisfied,* this will be the same as the point on body 2.



  '*/

  DECLARE SUB dJointGetBallAnchor  LIB "ode.dll" ALIAS "dJointGetBallAnchor" (BYVAL dJointIDlike AS dJointID, BYVAL result() AS dReal)



  '/**

  '* @brief Get the joint anchor point, in world coordinates.

  '*

  '* This returns the point on body 2. You can think of a ball and socket

  '* joint as trying to keep the result of dJointGetBallAnchor() and

  '* dJointGetBallAnchor2() the same. If the joint is perfectly satisfied,* this function will return the same value as dJointGetBallAnchor() to



  '* within roundoff errors. dJointGetBallAnchor2() can be used, along with

  '* dJointGetBallAnchor(), to see how far the joint has come apart.

  '*/

  DECLARE SUB dJointGetBallAnchor2  LIB "ode.dll" ALIAS "dJointGetBallAnchor2" (BYVAL dJointIDlike AS dJointID, BYVAL result() AS dReal)



  '/**

  '* @brief Get the hinge anchor point, in world coordinates.

  '*

  '* This returns the point on body 1. If the joint is perfectly satisfied,* this will be the same as the point on body 2.



  '* @ingroup joints

  '*/

  DECLARE SUB dJointGetHingeAnchor  LIB "ode.dll" ALIAS "dJointGetHingeAnchor" (BYVAL dJointIDlike AS dJointID, BYVAL result() AS dReal)



  '/**

  '* @brief Get the joint anchor point, in world coordinates.

  '* @return The point on body 2. If the joint is perfectly satisfied,* this will return the same value as dJointGetHingeAnchor().



  '* If not, this value will be slightly different.

  '* This can be used, for example, to see how far the joint has come apart.

  '* @ingroup joints

  '*/

  DECLARE SUB dJointGetHingeAnchor2  LIB "ode.dll" ALIAS "dJointGetHingeAnchor2" (BYVAL dJointIDlike AS dJointID, BYVAL result() AS dReal)



  '/**

  '* @brief get axis

  '* @ingroup joints

  '*/

  DECLARE SUB dJointGetHingeAxis  LIB "ode.dll" ALIAS "dJointGetHingeAxis" (BYVAL dJointIDlike AS dJointID, BYVAL result() AS dReal)



  '/**

  '* @brief get joint parameter

  '* @ingroup joints

  '*/

  DECLARE FUNCTION  dJointGetHingeParam  LIB "ode.dll" ALIAS "dJointGetHingeParam" (BYVAL dJointIDlike AS dJointID, BYVAL parameter AS LONG) AS dReal



  '/**

  '* @brief Get the hinge angle.

  '*

  '* The angle is measured between the two bodies, or between the body and

  '* the static environment.

  '* The angle will be between -pi..pi.

  '* When the hinge anchor or axis is set, the current position of the attached

  '* bodies is examined and that position will be the zero angle.

  '* @ingroup joints

  '*/

  DECLARE FUNCTION  dJointGetHingeAngle  LIB "ode.dll" ALIAS "dJointGetHingeAngle" (BYVAL dJointIDlike AS dJointID) AS dReal



  '/**

  '* @brief Get the hinge angle time derivative.

  '* @ingroup joints

  '*/

  DECLARE FUNCTION  dJointGetHingeAngleRate  LIB "ode.dll" ALIAS "dJointGetHingeAngleRate" (BYVAL dJointIDlike AS dJointID) AS dReal



  '/**

  '* @brief Get the slider linear position (i.e. the slider's extension)

  '*

  '* When the axis is set, the current position of the attached bodies is

  '* examined and that position will be the zero position.

  '* @ingroup joints

  '*/

  DECLARE FUNCTION  dJointGetSliderPosition  LIB "ode.dll" ALIAS "dJointGetSliderPosition" (BYVAL dJointIDlike AS dJointID) AS dReal



  '/**

  '* @brief Get the slider linear position's time derivative.

  '* @ingroup joints

  '*/

  DECLARE FUNCTION  dJointGetSliderPositionRate  LIB "ode.dll" ALIAS "dJointGetSliderPositionRate" (BYVAL dJointIDlike AS dJointID) AS dReal



  '/**

  '* @brief Get the slider axis

  '* @ingroup joints

  '*/

  DECLARE SUB dJointGetSliderAxis  LIB "ode.dll" ALIAS "dJointGetSliderAxis" (BYVAL dJointIDlike AS dJointID, BYVAL result() AS dReal)



  '/**

  '* @brief get joint parameter

  '* @ingroup joints

  '*/

  DECLARE FUNCTION  dJointGetSliderParam  LIB "ode.dll" ALIAS "dJointGetSliderParam" (BYVAL dJointIDlike AS dJointID, BYVAL parameter AS LONG) AS dReal



  '/**

  '* @brief Get the joint anchor point, in world coordinates.

  '* @return the point on body 1. If the joint is perfectly satisfied,* this will be the same as the point on body 2.



  '* @ingroup joints

  '*/

  DECLARE SUB dJointGetHinge2Anchor  LIB "ode.dll" ALIAS "dJointGetHinge2Anchor" (BYVAL dJointIDlike AS dJointID, BYVAL result() AS dReal)



  '/**

  '* @brief Get the joint anchor point, in world coordinates.

  '* This returns the point on body 2. If the joint is perfectly satisfied,* this will return the same value as dJointGetHinge2Anchor.



  '* If not, this value will be slightly different.

  '* This can be used, for example, to see how far the joint has come apart.

  '* @ingroup joints

  '*/

  DECLARE SUB dJointGetHinge2Anchor2  LIB "ode.dll" ALIAS "dJointGetHinge2Anchor2" (BYVAL dJointIDlike AS dJointID, BYVAL result() AS dReal)



  '/**

  '* @brief Get joint axis

  '* @ingroup joints

  '*/

  DECLARE SUB dJointGetHinge2Axis1  LIB "ode.dll" ALIAS "dJointGetHinge2Axis1" (BYVAL dJointIDlike AS dJointID, BYVAL result() AS dReal)



  '/**

  '* @brief Get joint axis

  '* @ingroup joints

  '*/

  DECLARE SUB dJointGetHinge2Axis2  LIB "ode.dll" ALIAS "dJointGetHinge2Axis2" (BYVAL dJointIDlike AS dJointID, BYVAL result() AS dReal)



  '/**

  '* @brief get joint parameter

  '* @ingroup joints

  '*/

  DECLARE FUNCTION  dJointGetHinge2Param  LIB "ode.dll" ALIAS "dJointGetHinge2Param" (BYVAL dJointIDlike AS dJointID, BYVAL parameter AS LONG) AS dReal



  '/**

  '* @brief Get angle

  '* @ingroup joints

  '*/

  DECLARE FUNCTION  dJointGetHinge2Angle1  LIB "ode.dll" ALIAS "dJointGetHinge2Angle1" (BYVAL dJointIDlike AS dJointID) AS dReal



  '/**

  '* @brief Get time derivative of angle

  '* @ingroup joints

  '*/

  DECLARE FUNCTION  dJointGetHinge2Angle1Rate  LIB "ode.dll" ALIAS "dJointGetHinge2Angle1Rate" (BYVAL dJointIDlike AS dJointID) AS dReal



  '/**

  '* @brief Get time derivative of angle

  '* @ingroup joints

  '*/

  DECLARE FUNCTION  dJointGetHinge2Angle2Rate  LIB "ode.dll" ALIAS "dJointGetHinge2Angle2Rate" (BYVAL dJointIDlike AS dJointID) AS dReal



  '/**

  '* @brief Get the joint anchor point, in world coordinates.

  '* @return the point on body 1. If the joint is perfectly satisfied,* this will be the same as the point on body 2.



  '* @ingroup joints

  '*/

  DECLARE SUB dJointGetUniversalAnchor  LIB "ode.dll" ALIAS "dJointGetUniversalAnchor" (BYVAL dJointIDlike AS dJointID, BYVAL result() AS dReal)



  '/**

  '* @brief Get the joint anchor point, in world coordinates.

  '* @return This returns the point on body 2.

  '* @remarks

  '* You can think of the ball and socket part of a universal joint as

  '* trying to keep the result of dJointGetBallAnchor() and

  '* dJointGetBallAnchor2() the same. If the joint is

  '* perfectly satisfied, this function will return the same value

  '* as dJointGetUniversalAnchor() to within roundoff errors.

  '* dJointGetUniversalAnchor2() can be used, along with

  '* dJointGetUniversalAnchor(), to see how far the joint has come apart.

  '* @ingroup joints

  '*/

  DECLARE SUB dJointGetUniversalAnchor2  LIB "ode.dll" ALIAS "dJointGetUniversalAnchor2" (BYVAL dJointIDlike AS dJointID, BYVAL result() AS dReal)



  '/**

  '* @brief Get axis

  '* @ingroup joints

  '*/

  DECLARE SUB dJointGetUniversalAxis1  LIB "ode.dll" ALIAS "dJointGetUniversalAxis1" (BYVAL dJointIDlike AS dJointID, BYVAL result() AS dReal)



  '/**

  '* @brief Get axis

  '* @ingroup joints

  '*/

  DECLARE SUB dJointGetUniversalAxis2  LIB "ode.dll" ALIAS "dJointGetUniversalAxis2" (BYVAL dJointIDlike AS dJointID, BYVAL result() AS dReal)





  '/**

  '* @brief get joint parameter

  '* @ingroup joints

  '*/

  DECLARE FUNCTION  dJointGetUniversalParam  LIB "ode.dll" ALIAS "dJointGetUniversalParam" (BYVAL dJointIDlike AS dJointID, BYVAL parameter AS LONG) AS dReal



  '/**

  '* @brief Get both angles at the same time.

  '* @ingroup joints

  '*

  '* @param joint The universal joint for which we want to calculate the angles

  '* @param angle1 The angle between the body1 and the axis 1

  '* @param angle2 The angle between the body2 and the axis 2

  '*

  '* @note This function combine getUniversalAngle1 and getUniversalAngle2 together

  '* and try to avoid redundant calculation

  '*/

  DECLARE SUB dJointGetUniversalAngles  LIB "ode.dll" ALIAS "dJointGetUniversalAngles" (BYVAL dJointIDlike AS dJointID, BYREF angle1 AS dReal, BYREF angle2 AS dReal)



  '/**

  '* @brief Get angle

  '* @ingroup joints

  '*/

  DECLARE FUNCTION  dJointGetUniversalAngle1  LIB "ode.dll" ALIAS "dJointGetUniversalAngle1" (BYVAL dJointIDlike AS dJointID) AS dReal



  '/**

  '* @brief Get angle

  '* @ingroup joints

  '*/

  DECLARE FUNCTION  dJointGetUniversalAngle2  LIB "ode.dll" ALIAS "dJointGetUniversalAngle2" (BYVAL dJointIDlike AS dJointID) AS dReal



  '/**

  '* @brief Get time derivative of angle

  '* @ingroup joints

  '*/

  DECLARE FUNCTION  dJointGetUniversalAngle1Rate  LIB "ode.dll" ALIAS "dJointGetUniversalAngle1Rate" (BYVAL dJointIDlike AS dJointID) AS dReal



  '/**

  '* @brief Get time derivative of angle

  '* @ingroup joints

  '*/

  DECLARE FUNCTION  dJointGetUniversalAngle2Rate  LIB "ode.dll" ALIAS "dJointGetUniversalAngle2Rate" (BYVAL dJointIDlike AS dJointID) AS dReal







  '/**

  '* @brief Get the joint anchor point, in world coordinates.

  '* @return the point on body 1. If the joint is perfectly satisfied, * this will be the same as the point on body 2.



  '* @ingroup joints

  '*/

  DECLARE SUB dJointGetPRAnchor  LIB "ode.dll" ALIAS "dJointGetPRAnchor" (BYVAL dJointIDlike AS dJointID, BYVAL result() AS dReal)



  '/**

  '* @brief Get the PR linear position (i.e. the prismatic's extension)

  '*

  '* When the axis is set, the current position of the attached bodies is

  '* examined and that position will be the zero position.

  '*

  '* The position is the "oriented" length between the

  '* position = (Prismatic axis) dot_product [(body1 + offset) - (body2 + anchor2)]

  '*

  '* @ingroup joints

  '*/

  DECLARE FUNCTION  dJointGetPRPosition  LIB "ode.dll" ALIAS "dJointGetPRPosition" (BYVAL dJointIDlike AS dJointID) AS dReal



  '/**

  '* @brief Get the PR linear position's time derivative

  '*

  '* @ingroup joints

  '*/

  DECLARE FUNCTION  dJointGetPRPositionRate  LIB "ode.dll" ALIAS "dJointGetPRPositionRate" (BYVAL dJointIDlike AS dJointID) AS dReal





  '/**

  '* @brief Get the prismatic axis

  '* @ingroup joints

  '*/

  DECLARE SUB dJointGetPRAxis1  LIB "ode.dll" ALIAS "dJointGetPRAxis1" (BYVAL dJointIDlike AS dJointID, BYVAL result() AS dReal)



  '/**

  '* @brief Get the Rotoide axis

  '* @ingroup joints

  '*/

  DECLARE SUB dJointGetPRAxis2  LIB "ode.dll" ALIAS "dJointGetPRAxis2" (BYVAL dJointIDlike AS dJointID, BYVAL result() AS dReal)



  '/**

  '* @brief get joint parameter

  '* @ingroup joints

  '*/

  DECLARE FUNCTION  dJointGetPRParam  LIB "ode.dll" ALIAS "dJointGetPRParam" (BYVAL dJointIDlike AS dJointID, BYVAL parameter AS LONG) AS dReal







  '/**

  '* @brief Get the number of angular axes that will be controlled by the

  '* AMotor.

  '* @param num can range from 0 (which effectively deactivates the

  '* joint) to 3.

  '* This is automatically set to 3 in dAMotorEuler mode.

  '* @ingroup joints

  '*/

  DECLARE FUNCTION  dJointGetAMotorNumAxes  LIB "ode.dll" ALIAS "dJointGetAMotorNumAxes" (BYVAL dJointIDlike AS dJointID) AS LONG



  '/**

  '* @brief Get the AMotor axes.

  '* @param anum selects the axis to change (0,1 or 2).

  '* @param rel Each axis can have one of three ``relative orientation'' modes.

  '* \li 0: The axis is anchored to the global frame.

  '* \li 1: The axis is anchored to the first body.

  '* \li 2: The axis is anchored to the second body.

  '* @ingroup joints

  '*/

  DECLARE SUB dJointGetAMotorAxis  LIB "ode.dll" ALIAS "dJointGetAMotorAxis" (BYVAL dJointIDlike AS dJointID, BYVAL anum AS LONG, BYVAL result() AS dReal)



  '/**

  '* @brief Get axis

  '* @remarks

  '* The axis vector is always specified in global coordinates regardless

  '* of the setting of rel.

  '* There are two GetAMotorAxis functions, one to return the axis and one to

  '* return the relative mode.

  '*

  '* For dAMotorEuler mode:

  '* \li  Only axes 0 and 2 need to be set. Axis 1 will be determined

  '  automatically at each time step.

  '* \li  Axes 0 and 2 must be perpendicular to each other.

  '* \li  Axis 0 must be anchored to the first body, axis 2 must be anchored

   ' to the second body.

  '* @ingroup joints

  '*/

  DECLARE FUNCTION  dJointGetAMotorAxisRel  LIB "ode.dll" ALIAS "dJointGetAMotorAxisRel" (BYVAL dJointIDlike AS dJointID, BYVAL anum AS LONG) AS LONG



  '/**

  '* @brief Get the current angle for axis.

  '* @remarks

  '* In dAMotorUser mode this is simply the value that was set with

  '* dJointSetAMotorAngle().

  '* In dAMotorEuler mode this is the corresponding euler angle.

  '* @ingroup joints

  '*/

  DECLARE FUNCTION  dJointGetAMotorAngle  LIB "ode.dll" ALIAS "dJointGetAMotorAngle" (BYVAL dJointIDlike AS dJointID, BYVAL anum AS LONG) AS dReal



  '/**

  '* @brief Get the current angle rate for axis anum.

  '* @remarks

  '* In dAMotorUser mode this is always zero, as not enough information is

  '* available.

  '* In dAMotorEuler mode this is the corresponding euler angle rate.

  '* @ingroup joints

  '*/

  DECLARE FUNCTION  dJointGetAMotorAngleRate  LIB "ode.dll" ALIAS "dJointGetAMotorAngleRate" (BYVAL dJointIDlike AS dJointID, BYVAL anum AS LONG) AS dReal



  '/**

  '* @brief get joint parameter

  '* @ingroup joints

  '*/

  DECLARE FUNCTION  dJointGetAMotorParam  LIB "ode.dll" ALIAS "dJointGetAMotorParam" (BYVAL dJointIDlike AS dJointID, BYVAL parameter AS LONG) AS dReal



  '/**

  '* @brief Get the angular motor mode.

  '* @param mode must be one of the following constants:

  '* \li dAMotorUser The AMotor axes and joint angle settings are entirely

  '* controlled by the user. This is the default mode.

  '* \li dAMotorEuler Euler angles are automatically computed.

  '* The axis a1 is also automatically computed.

  '* The AMotor axes must be set correctly when in this mode,* as described below.



  '* When this mode is initially set the current relative orientations

  '* of the bodies will correspond to all euler angles at zero.

  '* @ingroup joints

  '*/

  DECLARE FUNCTION  dJointGetAMotorMode  LIB "ode.dll" ALIAS "dJointGetAMotorMode" (BYVAL dJointIDlike AS dJointID) AS LONG



  '/**

  '* @brief Get nr of axes.

  '* @ingroup joints

  '*/

  DECLARE FUNCTION  dJointGetLMotorNumAxes  LIB "ode.dll" ALIAS "dJointGetLMotorNumAxes" (BYVAL dJointIDlike AS dJointID) AS LONG



  '/**

  '* @brief Get axis.

  '* @ingroup joints

  '*/

  DECLARE SUB dJointGetLMotorAxis  LIB "ode.dll" ALIAS "dJointGetLMotorAxis" (BYVAL dJointIDlike AS dJointID, BYVAL anum AS LONG, BYVAL result() AS dReal)



  '/**

  '* @brief get joint parameter

  '* @ingroup joints

  '*/

  DECLARE FUNCTION  dJointGetLMotorParam  LIB "ode.dll" ALIAS "dJointGetLMotorParam" (BYVAL dJointIDlike AS dJointID, BYVAL parameter AS LONG) AS dReal





  '/**

  '* @ingroup joints

  '*/

  DECLARE FUNCTION  dConnectingJoint  LIB "ode.dll" ALIAS "dConnectingJoint" (BYVAL dBodyIDlike AS dBodyID, BYVAL dBodyIDlike AS dBodyID) AS dJointID



  '/**

  '* @ingroup joints

  '*/

  DECLARE FUNCTION  dConnectingJointList  LIB "ode.dll" ALIAS "dConnectingJointList" (BYVAL dBodyIDlike AS dBodyID, BYVAL dBodyIDlike AS dBodyID, BYREF dJoint AS dJointID) AS LONG



  '/**

  '* @brief Utility function

  '* @return 1 if the two bodies are connected together by

  '* a joint, otherwise return 0.

  '* @ingroup joints

  '*/

  DECLARE FUNCTION  dAreConnected  LIB "ode.dll" ALIAS "dAreConnected" (BYVAL dBodyIDlike AS dBodyID, BYVAL dBodyIDlike AS dBodyID) AS LONG



  '/**

  '* @brief Utility function

  '* @return 1 if the two bodies are connected together by

  '* a joint that does not have type @arg{joint_type}, otherwise return 0.

  '* @param body1 A body to check.

  '* @param body2 A body to check.

  '* @param joint_type is a dJointTypeXXX constant.

  '* This is useful for deciding whether to add contact joints between two bodies:

  '* if they are already connected by non-contact joints then it may not be

  '* appropriate to add contacts, however it is okay to add more contact between-

  '* bodies that already have contacts.

  '* @ingroup joints

  '*/

  DECLARE FUNCTION  dAreConnectedExcluding  LIB "ode.dll" ALIAS "dAreConnectedExcluding" (BYVAL body1 AS dBodyID, BYVAL body2 AS dBodyID, BYVAL joint_type AS LONG) AS LONG


   
  '=============================================================================
  '=                             collision_space.h                             =
  '=============================================================================

  DECLARE FUNCTION  dSimpleSpaceCreate  LIB "ode.dll" ALIAS "dSimpleSpaceCreate" (BYVAL space AS dSpaceID) AS dSpaceID
  DECLARE FUNCTION  dHashSpaceCreate  LIB "ode.dll" ALIAS "dHashSpaceCreate" (BYVAL space AS dSpaceID) AS dSpaceID
  DECLARE FUNCTION  dQuadTreeSpaceCreate  LIB "ode.dll" ALIAS "dQuadTreeSpaceCreate" (BYVAL space AS dSpaceID, BYVAL Center() AS dReal, BYVAL Extents() AS dReal, BYVAL Depth AS LONG) AS dSpaceID

  DECLARE SUB dSpaceDestroy  LIB "ode.dll" ALIAS "dSpaceDestroy" (BYVAL dSpace AS dSpaceID)

  DECLARE SUB dHashSpaceSetLevels  LIB "ode.dll" ALIAS "dHashSpaceSetLevels" (BYVAL space AS dSpaceID, BYVAL minlevel AS LONG, BYVAL maxlevel AS LONG)
  DECLARE SUB dHashSpaceGetLevels  LIB "ode.dll" ALIAS "dHashSpaceGetLevels" (BYVAL space AS dSpaceID, BYREF minlevel AS LONG, BYREF maxlevel AS LONG)

  DECLARE SUB dSpaceSetCleanup  LIB "ode.dll" ALIAS "dSpaceSetCleanup" (BYVAL space AS dSpaceID, BYVAL mode AS LONG)
  DECLARE FUNCTION  dSpaceGetCleanup  LIB "ode.dll" ALIAS "dSpaceGetCleanup" (BYVAL space AS dSpaceID) AS LONG

  DECLARE SUB dSpaceAdd  LIB "ode.dll" ALIAS "dSpaceAdd" (BYVAL dSpace AS dSpaceID, BYVAL dGeomIDlike AS dGeomID)
  DECLARE SUB dSpaceRemove  LIB "ode.dll" ALIAS "dSpaceRemove" (BYVAL dSpace AS dSpaceID, BYVAL dGeomIDlike AS dGeomID)
  DECLARE FUNCTION  dSpaceQuery  LIB "ode.dll" ALIAS "dSpaceQuery" (BYVAL dSpace AS dSpaceID, BYVAL dGeomIDlike AS dGeomID) AS LONG
  DECLARE SUB dSpaceClean  LIB "ode.dll" ALIAS "dSpaceClean" (BYVAL dSpace AS dSpaceID)
  DECLARE FUNCTION  dSpaceGetNumGeoms  LIB "ode.dll" ALIAS "dSpaceGetNumGeoms" (BYVAL dSpace AS dSpaceID) AS LONG
  DECLARE FUNCTION  dSpaceGetGeom  LIB "ode.dll" ALIAS "dSpaceGetGeom" (BYVAL dSpace AS dSpaceID, BYVAL i AS LONG) AS dGeomID
  
  '=============================================================================
  '=                                collision.h                                = - PART "A"
  '=============================================================================

  '/**
  '* @defgroup collide Collision Detection
  '*
  '* ODE has two main components: a dynamics simulation engine and a collision
  '* detection engine. The collision engine is given information about the
  '* shape of each body. At each time step it figures out which bodies touch
  '* each other and passes the resulting contact point information to the user.
  '* The user in turn creates contact joints between bodies.
  '*
  '* Using ODE's collision detection is optional - an alternative collision
  '* detection system can be used as long as it can supply the right kinds of
  '* contact information.
  '*/


  '/* ************************************************************************ */
  '/* general functions */

  '/**
  '* @brief Destroy a geom, removing it from any space.
  '*
  '* Destroy a geom, removing it from any space it is in first. This one
  '* function destroys a geom of any type, but to create a geom you must call
  '* a creation function for that type.
  '*
  '* When a space is destroyed, if its cleanup mode is 1 (the default) then all
  '* the geoms in that space are automatically destroyed as well.
  '*
  '* @param geom the geom to be destroyed.
  '* @ingroup collide
  '*/
  DECLARE SUB dGeomDestroy  LIB "ode.dll" ALIAS "dGeomDestroy" (BYVAL geom AS dGeomID)


  '/**
  '* @brief Set the user-defined data pointer stored in the geom.
  '*
  '* @param geom the geom to hold the data
  '* @param data the data pointer to be stored
  '* @ingroup collide
  '*/
  DECLARE SUB dGeomSetData  LIB "ode.dll" ALIAS "dGeomSetData" (BYVAL geom AS dGeomID, BYREF data as DWORD)


  '/**
  '* @brief Get the user-defined data pointer stored in the geom.
  '*
  '* @param geom the geom containing the data
  '* @ingroup collide
  '*/
  DECLARE function dGeomGetData  LIB "ode.dll" ALIAS "dGeomGetData" (BYVAL geom AS dGeomID) AS DWORD


  '/**
  '* @brief Set the body associated with a placeable geom.
  '*
  '* Setting a body on a geom automatically combines the position vector and
  '* rotation matrix of the body and geom, so that setting the position or
  '* orientation of one will set the value for both objects. Setting a body
  '* ID of zero gives the geom its own position and rotation, independent
  '* from any body. If the geom was previously connected to a body then its
  '* new independent position/rotation is set to the current position/rotation
  '* of the body.
  '*
  '* Calling these functions on a non-placeable geom results in a runtime
  '* error in the debug build of ODE.
  '*
  '* @param geom the geom to connect
  '* @param body the body to attach to the geom
  '* @ingroup collide
  '*/
  DECLARE SUB dGeomSetBody  LIB "ode.dll" ALIAS "dGeomSetBody" (BYVAL geom AS dGeomID, BYVAL body AS dBodyID)


  '/**
  '* @brief Get the body associated with a placeable geom.
  '* @param geom the geom to query.
  '* @sa dGeomSetBody
  '* @ingroup collide
  '*/
  DECLARE FUNCTION  dGeomGetBody  LIB "ode.dll" ALIAS "dGeomGetBody" (BYVAL geom AS dGeomID) AS dBodyID


  '/**
  '* @brief Set the position vector of a placeable geom.
  '*
  '* If the geom is attached to a body, the body's position will also be changed.
  '* Calling this function on a non-placeable geom results in a runtime error in
  '* the debug build of ODE.
  '*
  '* @param geom the geom to set.
  '* @param x the new X coordinate.
  '* @param y the new Y coordinate.
  '* @param z the new Z coordinate.
  '* @sa dBodySetPosition
  '* @ingroup collide
  '*/
  DECLARE SUB dGeomSetPosition  LIB "ode.dll" ALIAS "dGeomSetPosition" (BYVAL geom AS dGeomID, BYVAL x AS dReal, BYVAL y AS dReal, BYVAL z AS dReal)


  '/**
  '* @brief Set the rotation matrix of a placeable geom.
  '*
  '* If the geom is attached to a body, the body's rotation will also be changed.
  '* Calling this function on a non-placeable geom results in a runtime error in
  '* the debug build of ODE.
  '*
  '* @param geom the geom to set.
  '* @param R the new rotation matrix.
  '* @sa dBodySetRotation
  '* @ingroup collide
  '*/
  DECLARE SUB dGeomSetRotation  LIB "ode.dll" ALIAS "dGeomSetRotation" (BYVAL geom AS dGeomID, BYVAL R() AS dReal)


  '/**
  '* @brief Set the rotation of a placeable geom.
  '*
  '* If the geom is attached to a body, the body's rotation will also be changed.
  '*
  '* Calling this function on a non-placeable geom results in a runtime error in
  '* the debug build of ODE.
  '*
  '* @param geom the geom to set.
  '* @param Q the new rotation.
  '* @sa dBodySetQuaternion
  '* @ingroup collide
  '*/
  DECLARE SUB dGeomSetQuaternion  LIB "ode.dll" ALIAS "dGeomSetQuaternion" (BYVAL geom AS dGeomID, BYVAL Q() AS dReal)


  '/**
  '* @brief Get the position vector of a placeable geom.
  '*
  '* If the geom is attached to a body, the body's position will be returned.
  '*
  '* Calling this function on a non-placeable geom results in a runtime error in
  '* the debug build of ODE.
  '*
  '* @param geom the geom to query.
  '* @returns A pointer to the geom's position vector.
  '* @remarks The returned value is a pointer to the geom's internal
  '* data structure. It is valid until any changes are made
  '* to the geom.
  '* @sa dBodyGetPosition
  '* @ingroup collide
  '*/
  DECLARE FUNCTION   dGeomGetPosition  LIB "ode.dll" ALIAS "dGeomGetPosition" (BYVAL geom AS dGeomID) AS dword


  '/**
  '* @brief Copy the position of a geom into a vector.
  '* @ingroup collide
  '* @param geom the geom to query
  '* @param pos a copy of the geom position
  '* @sa dGeomGetPosition
  '*/
  DECLARE SUB dGeomCopyPosition  LIB "ode.dll" ALIAS "dGeomCopyPosition" (BYVAL geom AS dGeomID, BYVAL pos() AS dReal)


  '/**
  '* @brief Get the rotation matrix of a placeable geom.
  '*
  '* If the geom is attached to a body, the body's rotation will be returned.
  '*
  '* Calling this function on a non-placeable geom results in a runtime error in
  '* the debug build of ODE.
  '*
  '* @param geom the geom to query.
  '* @returns A pointer to the geom's rotation matrix.
  '* @remarks The returned value is a pointer to the geom's internal
  '* data structure. It is valid until any changes are made
  '* to the geom.
  '* @sa dBodyGetRotation
  '* @ingroup collide
  '*/
  DECLARE FUNCTION   dGeomGetRotation  LIB "ode.dll" ALIAS "dGeomGetRotation" (BYVAL geom AS dGeomID) AS dword


  '/**
  '* @brief Get the rotation matrix of a placeable geom.
  '*
  '* If the geom is attached to a body, the body's rotation will be returned.
  '*
  '* Calling this function on a non-placeable geom results in a runtime error in
  '* the debug build of ODE.
  '*
  '* @param geom the geom to query.
  '* @param R a copy of the geom rotation
  '* @sa dGeomGetRotation
  '* @ingroup collide
  '*/
  DECLARE SUB dGeomCopyRotation LIB "ode.dll" ALIAS "dGeomCopyRotation" (BYVAL geom AS dGeomID, BYVAL R() AS dReal)


  '/**
  '* @brief Get the rotation quaternion of a placeable geom.
  '*
  '* If the geom is attached to a body, the body's quaternion will be returned.
  '*
  '* Calling this function on a non-placeable geom results in a runtime error in
  '* the debug build of ODE.
  '*
  '* @param geom the geom to query.
  '* @param result a copy of the rotation quaternion.
  '* @sa dBodyGetQuaternion
  '* @ingroup collide
  '*/
  DECLARE function dGeomGetQuaternion  LIB "ode.dll" ALIAS "dGeomGetQuaternion" (BYVAL geom AS dGeomID, BYVAL result() AS dReal) AS DWORD


  '/**
  '* @brief Return the axis-aligned bounding box.
  '*
  '* Return in aabb an axis aligned bounding box that surrounds the given geom.
  '* The aabb array has elements (minx, maxx, miny, maxy, minz, maxz). If the
  '* geom is a space, a bounding box that surrounds all contained geoms is
  '* returned.
  '*
  '* This function may return a pre-computed cached bounding box, if it can
  '* determine that the geom has not moved since the last time the bounding
  '* box was computed.
  '*
  '* @param geom the geom to query
  '* @param aabb the returned bounding box
  '* @ingroup collide
  '*/
  DECLARE SUB dGeomGetAABB  LIB "ode.dll" ALIAS "dGeomGetAABB" (BYVAL geom AS dGeomID, BYVAL aabb() AS dReal)


  '/**
  '* @brief Determing if a geom is a space.
  '* @param geom the geom to query
  '* @returns Non-zero if the geom is a space, zero otherwise.
  '* @ingroup collide
  '*/
  DECLARE FUNCTION  dGeomIsSpace  LIB "ode.dll" ALIAS "dGeomIsSpace" (BYVAL geom AS dGeomID) AS LONG


  '/**
  '* @brief Query for the space containing a particular geom.
  '* @param geom the geom to query
  '* @returns The space that contains the geom, or NULL if the geom is
  '* not contained by a space.
  '* @ingroup collide
  '*/
  DECLARE FUNCTION  dGeomGetSpace  LIB "ode.dll" ALIAS "dGeomGetSpace" (BYVAL dGeomIDlike AS dGeomID) AS dSpaceID


  '/**
  '* @brief Given a geom, this returns its class.
  '*
  '* The ODE classes are:
  '* @li dSphereClass
  '* @li dBoxClass
  '* @li dCylinderClass
  '* @li dPlaneClass
  '* @li dRayClass
  '* @li dConvexClass
  '* @li dGeomTransformClass
  '* @li dTriMeshClass
  '* @li dSimpleSpaceClass
  '* @li dHashSpaceClass
  '* @li dQuadTreeSpaceClass
  '* @li dFirstUserClass
  '* @li dLastUserClass
  '*
  '* User-defined class will return their own number.
  '*
  '* @param geom the geom to query
  '* @returns The geom class ID.
  '* @ingroup collide
  '*/
  DECLARE FUNCTION  dGeomGetClass  LIB "ode.dll" ALIAS "dGeomGetClass" (BYVAL geom AS dGeomID) AS LONG


  '/**
  '* @brief Set the "category" bitfield for the given geom.
  '*
  '* The category bitfield is used by spaces to govern which geoms will
  '* interact with each other. The bitfield is guaranteed to be at least
  '* 32 bits wide. The default category values for newly created geoms
  '* have all bits set.
  '*
  '* @param geom the geom to set
  '* @param bits the new bitfield value
  '* @ingroup collide
  '*/
  DECLARE SUB dGeomSetCategoryBits  LIB "ode.dll" ALIAS "dGeomSetCategoryBits" (BYVAL geom AS dGeomID, BYVAL bits AS dword)


  '/**
  '* @brief Set the "collide" bitfield for the given geom.
  '*
  '* The collide bitfield is used by spaces to govern which geoms will
  '* interact with each other. The bitfield is guaranteed to be at least
  '* 32 bits wide. The default category values for newly created geoms
  '* have all bits set.
  '*
  '* @param geom the geom to set
  '* @param bits the new bitfield value
  '* @ingroup collide
  '*/
  DECLARE SUB dGeomSetCollideBits  LIB "ode.dll" ALIAS "dGeomSetCollideBits" (BYVAL geom AS dGeomID, BYVAL bits AS dword)


  '/**
  '* @brief Get the "category" bitfield for the given geom.
  '*
  '* @param geom the geom to set
  '* @param bits the new bitfield value
  '* @sa dGeomSetCategoryBits
  '* @ingroup collide
  '*/
  DECLARE FUNCTION dGeomGetCategoryBits  LIB "ode.dll" ALIAS "dGeomGetCategoryBits" (BYVAL dGeomIDlike AS dGeomID) AS dword


  '/**
  '* @brief Get the "collide" bitfield for the given geom.
  '*
  '* @param geom the geom to set
  '* @param bits the new bitfield value
  '* @sa dGeomSetCollideBits
  '* @ingroup collide
  '*/
  DECLARE FUNCTION  dGeomGetCollideBits  LIB "ode.dll" ALIAS "dGeomGetCollideBits" (BYVAL dGeomIDlike AS dGeomID) AS dword


  '/**
  '* @brief Enable a geom.
  '*
  '* Disabled geoms are completely ignored by dSpaceCollide and dSpaceCollide2,* although they can still be members of a space. New geoms are created in

  '* the enabled state.
  '*
  '* @param geom the geom to enable
  '* @sa dGeomDisable
  '* @sa dGeomIsEnabled
  '* @ingroup collide
  '*/
  DECLARE SUB dGeomEnable  LIB "ode.dll" ALIAS "dGeomEnable" (BYVAL geom AS dGeomID)


  '/**
  '* @brief Disable a geom.
  '*
  '* Disabled geoms are completely ignored by dSpaceCollide and dSpaceCollide2,* although they can still be members of a space. New geoms are created in

  '* the enabled state.
  '*
  '* @param geom the geom to disable
  '* @sa dGeomDisable
  '* @sa dGeomIsEnabled
  '* @ingroup collide
  '*/
  DECLARE SUB dGeomDisable  LIB "ode.dll" ALIAS "dGeomDisable" (BYVAL geom AS dGeomID)


  '/**
  '* @brief Check to see if a geom is enabled.
  '*
  '* Disabled geoms are completely ignored by dSpaceCollide and dSpaceCollide2,* although they can still be members of a space. New geoms are created in

  '* the enabled state.
  '*
  '* @param geom the geom to query
  '* @returns Non-zero if the geom is enabled, zero otherwise.
  '* @sa dGeomDisable
  '* @sa dGeomIsEnabled
  '* @ingroup collide
  '*/
  DECLARE FUNCTION  dGeomIsEnabled  LIB "ode.dll" ALIAS "dGeomIsEnabled" (BYVAL geom AS dGeomID) AS LONG

  '/* ************************************************************************ */
  '/* geom offset from body */

  '/**
  '* @brief Set the local offset position of a geom from its body.
  '*
  '* Sets the geom's positional offset in local coordinates.
  '* After this call, the geom will be at a new position determined from the
  '* body's position and the offset.
  '* The geom must be attached to a body.
  '* If the geom did not have an offset, it is automatically created.
  '*
  '* @param geom the geom to set.
  '* @param x the new X coordinate.
  '* @param y the new Y coordinate.
  '* @param z the new Z coordinate.
  '* @ingroup collide
  '*/
  DECLARE function dGeomSetOffsetPosition  LIB "ode.dll" ALIAS "dGeomSetOffsetPosition" (BYVAL geom AS dGeomID, BYVAL x AS dReal, BYVAL y AS dReal, BYVAL z AS dReal) as dword


  '/**
  '* @brief Set the local offset rotation matrix of a geom from its body.
  '*
  '* Sets the geom's rotational offset in local coordinates.
  '* After this call, the geom will be at a new position determined from the
  '* body's position and the offset.
  '* The geom must be attached to a body.
  '* If the geom did not have an offset, it is automatically created.
  '*
  '* @param geom the geom to set.
  '* @param R the new rotation matrix.
  '* @ingroup collide
  '*/
  DECLARE SUB dGeomSetOffsetRotation  LIB "ode.dll" ALIAS "dGeomSetOffsetRotation" (BYVAL geom AS dGeomID, BYVAL R() AS dReal) 


  '/**
  '* @brief Set the local offset rotation of a geom from its body.
  '*
  '* Sets the geom's rotational offset in local coordinates.
  '* After this call, the geom will be at a new position determined from the
  '* body's position and the offset.
  '* The geom must be attached to a body.
  '* If the geom did not have an offset, it is automatically created.
  '*
  '* @param geom the geom to set.
  '* @param Q the new rotation.
  '* @ingroup collide
  '*/
  DECLARE SUB dGeomSetOffsetQuaternion  LIB "ode.dll" ALIAS "dGeomSetOffsetQuaternion" (BYVAL geom AS dGeomID, BYVAL Q() AS dReal)


  '/**
  '* @brief Set the offset position of a geom from its body.
  '*
  '* Sets the geom's positional offset to move it to the new world
  '* coordinates.
  '* After this call, the geom will be at the world position passed in,* and the offset will be the difference from the current body position.

  '* The geom must be attached to a body.
  '* If the geom did not have an offset, it is automatically created.
  '*
  '* @param geom the geom to set.
  '* @param x the new X coordinate.
  '* @param y the new Y coordinate.
  '* @param z the new Z coordinate.
  '* @ingroup collide
  '*/
  DECLARE SUB dGeomSetOffsetWorldPosition  LIB "ode.dll" ALIAS "dGeomSetOffsetWorldPosition" (BYVAL geom AS dGeomID, BYVAL x AS dReal, BYVAL y AS dReal, BYVAL z AS dReal)


  '/**
  '* @brief Set the offset rotation of a geom from its body.
  '*
  '* Sets the geom's rotational offset to orient it to the new world
  '* rotation matrix.
  '* After this call, the geom will be at the world orientation passed in,* and the offset will be the difference from the current body orientation.

  '* The geom must be attached to a body.
  '* If the geom did not have an offset, it is automatically created.
  '*
  '* @param geom the geom to set.
  '* @param R the new rotation matrix.
  '* @ingroup collide
  '*/
  DECLARE SUB dGeomSetOffsetWorldRotation  LIB "ode.dll" ALIAS "dGeomSetOffsetWorldRotation" (BYVAL geom AS dGeomID, BYVAL R() AS dReal)


  '/**
  '* @brief Set the offset rotation of a geom from its body.
  '*
  '* Sets the geom's rotational offset to orient it to the new world
  '* rotation matrix.
  '* After this call, the geom will be at the world orientation passed in,* and the offset will be the difference from the current body orientation.

  '* The geom must be attached to a body.
  '* If the geom did not have an offset, it is automatically created.
  '*
  '* @param geom the geom to set.
  '* @param Q the new rotation.
  '* @ingroup collide
  '*/
  DECLARE SUB dGeomSetOffsetWorldQuaternion  LIB "ode.dll" ALIAS "dGeomSetOffsetWorldQuaternion" (BYVAL geom AS dGeomID, BYVAL dQuaternion() AS dReal)


  '/**
  '* @brief Clear any offset from the geom.
  '*
  '* If the geom has an offset, it is eliminated and the geom is
  '* repositioned at the body's position. If the geom has no offset,* this function does nothing.

  '* This is more efficient than calling dGeomSetOffsetPosition(zero)
  '* and dGeomSetOffsetRotation(identiy), because this function actually
  '* eliminates the offset, rather than leaving it as the identity transform.
  '*
  '* @param geom the geom to have its offset destroyed.
  '* @ingroup collide
  '*/
  DECLARE SUB dGeomClearOffset LIB "ode.dll" ALIAS "dGeomClearOffset" (BYVAL geom AS dGeomID)


  '/**
  '* @brief Check to see whether the geom has an offset.
  '*
  '* This function will return non-zero if the offset has been created.
  '* Note that there is a difference between a geom with no offset,* and a geom with an offset that is the identity transform.

  '* In the latter case, although the observed behaviour is identical,* there is a unnecessary computation involved because the geom will

  '* be applying the transform whenever it needs to recalculate its world
  '* position.
  '*
  '* @param geom the geom to query.
  '* @returns Non-zero if the geom has an offset, zero otherwise.
  '* @ingroup collide
  '*/
  DECLARE FUNCTION  dGeomIsOffset LIB "ode.dll" ALIAS "dGeomIsOffset" (BYVAL geom AS dGeomID) AS LONG


  '/**
  '* @brief Get the offset position vector of a geom.
  '*
  '* Returns the positional offset of the geom in local coordinates.
  '* If the geom has no offset, this function returns the zero vector.
  '*
  '* @param geom the geom to query.
  '* @returns A pointer to the geom's offset vector.
  '* @remarks The returned value is a pointer to the geom's internal
  '* data structure. It is valid until any changes are made
  '* to the geom.
  '* @ingroup collide
  '*/
  DECLARE FUNCTION   dGeomGetOffsetPosition  LIB "ode.dll" ALIAS "dGeomGetOffsetPosition" (BYVAL geom AS dGeomID) AS dword


  '/**
  '* @brief Copy the offset position vector of a geom.
  '*
  '* Returns the positional offset of the geom in local coordinates.
  '* If the geom has no offset, this function returns the zero vector.
  '*
  '* @param geom the geom to query.
  '* @param pos returns the offset position
  '* @ingroup collide
  '*/
  DECLARE SUB dGeomCopyOffsetPosition  LIB "ode.dll" ALIAS "dGeomCopyOffsetPosition" (BYVAL geom AS dGeomID, BYVAL pos() AS dReal)


  '/**
  '* @brief Get the offset rotation matrix of a geom.
  '*
  '* Returns the rotational offset of the geom in local coordinates.
  '* If the geom has no offset, this function returns the identity
  '* matrix.
  '*
  '* @param geom the geom to query.
  '* @returns A pointer to the geom's offset rotation matrix.
  '* @remarks The returned value is a pointer to the geom's internal
  '* data structure. It is valid until any changes are made
  '* to the geom.
  '* @ingroup collide
  '*/
  DECLARE FUNCTION   dGeomGetOffsetRotation  LIB "ode.dll" ALIAS "dGeomGetOffsetRotation" (BYVAL geom AS dGeomID) AS dword


  '/**
  '* @brief Copy the offset rotation matrix of a geom.
  '*
  '* Returns the rotational offset of the geom in local coordinates.
  '* If the geom has no offset, this function returns the identity
  '* matrix.
  '*
  '* @param geom the geom to query.
  '* @param R returns the rotation matrix.
  '* @ingroup collide
  '*/
  DECLARE SUB dGeomCopyOffsetRotation  LIB "ode.dll" ALIAS "dGeomCopyOffsetRotation" (BYVAL geom AS dGeomID, BYVAL R() AS dReal)


  '/**
  '* @brief Get the offset rotation quaternion of a geom.
  '*
  '* Returns the rotation offset of the geom as a quaternion.
  '* If the geom has no offset, the identity quaternion is returned.
  '*
  '* @param geom the geom to query.
  '* @param result a copy of the rotation quaternion.
  '* @ingroup collide
  '*/
  DECLARE SUB dGeomGetOffsetQuaternion  LIB "ode.dll" ALIAS "dGeomGetOffsetQuaternion" (BYVAL geom AS dGeomID, BYVAL result() AS dReal)


  '/* ************************************************************************ */
  '/* collision detection */

  '/**
  '*
  '* @brief Given two geoms o1 and o2 that potentially intersect,* generate contact information for them.

  '*
  '* Internally, this just calls the correct class-specific collision
  '* functions for o1 and o2.
  '*
  '* @param o1 The first geom to test.
  '* @param o2 The second geom to test.
  '*
  '* @param flags The flags specify how contacts should be generated if
  '* the geoms touch. The lower 16 bits of flags is an integer that
  '* specifies the maximum number of contact points to generate. Note
  '* that if this number is zero, this function just pretends that it is
  '* one -- in other words you can not ask for zero contacts. All other bits
  '* in flags must be zero. In the future the other bits may be used to
  '* select from different contact generation strategies.
  '*
  '* @param contact Points to an array of dContactGeom structures. The array
  '* must be able to hold at least the maximum number of contacts. These
  '* dContactGeom structures may be embedded within larger structures in the
  '* array -- the skip parameter is the byte offset from one dContactGeom to
  '* the next in the array. If skip is sizeof(dContactGeom) then contact
  '* points to a normal (C-style) array. It is an error for skip to be smaller
  '* than sizeof(dContactGeom).
  '*
  '* @returns If the geoms intersect, this function returns the number of contact
  '* points generated (and updates the contact array), otherwise it returns 0
  '* (and the contact array is not touched).
  '*
  '* @remarks If a space is passed as o1 or o2 then this function will collide
  '* all objects contained in o1 with all objects contained in o2, and return
  '* the resulting contact points. This method for colliding spaces with geoms
  '* (or spaces with spaces) provides no user control over the individual
  '* collisions. To get that control, use dSpaceCollide or dSpaceCollide2 instead.
  '*
  '* @remarks If o1 and o2 are the same geom then this function will do nothing
  '* and return 0. Technically speaking an object intersects with itself, but it
  '* is not useful to find contact points in this case.
  '*
  '* @remarks This function does not care if o1 and o2 are in the same space or not
  '* (or indeed if they are in any space at all).
  '*
  '* @ingroup collide
  '*/
  DECLARE FUNCTION  dCollide  LIB "ode.dll" ALIAS "dCollide" (BYVAL o1 AS dGeomID, BYVAL o2 AS dGeomID, BYVAL flags AS LONG, BYREF contact AS dContactGeom, BYVAL skip AS LONG) AS LONG


  '/**
  '* @brief Determines which pairs of geoms in a space may potentially intersect,* and calls the callback function for each candidate pair.

  '*
  '* @param space The space to test.
  '*
  '* @param data Passed from dSpaceCollide directly to the callback
  '* function. Its meaning is user defined. The o1 and o2 arguments are the
  '* geoms that may be near each other.
  '*
  '* @param callback A callback function is of type @ref dNearCallback.
  '*
  '* @remarks Other spaces that are contained within the colliding space are
  '* not treated specially, i.e. they are not recursed into. The callback
  '* function may be passed these contained spaces as one or both geom
  '* arguments.
  '*
  '* @remarks dSpaceCollide() is guaranteed to pass all intersecting geom
  '* pairs to the callback function, but may also pass close but
  '* non-intersecting pairs. The number of these calls depends on the
  '* internal algorithms used by the space. Thus you should not expect
  '* that dCollide will return contacts for every pair passed to the
  '* callback.
  '*
  '* @sa dSpaceCollide2
  '* @ingroup collide
  '*/
  DECLARE SUB dSpaceCollide  LIB "ode.dll" ALIAS "dSpaceCollide" (BYVAL space AS dSpaceID, BYREF data as DWORD, BYREF callback AS dNearCallback)


  '/**
  '* @brief Determines which geoms from one space may potentially intersect with
  '* geoms from another space, and calls the callback function for each candidate
  '* pair.
  '*
  '* @param space1 The first space to test.
  '*
  '* @param space2 The second space to test.
  '*
  '* @param data Passed from dSpaceCollide directly to the callback
  '* function. Its meaning is user defined. The o1 and o2 arguments are the
  '* geoms that may be near each other.
  '*
  '* @param callback A callback function is of type @ref dNearCallback.
  '*
  '* @remarks This function can also test a single non-space geom against a
  '* space. This function is useful when there is a collision hierarchy, i.e.
  '* when there are spaces that contain other spaces.
  '*
  '* @remarks Other spaces that are contained within the colliding space are
  '* not treated specially, i.e. they are not recursed into. The callback
  '* function may be passed these contained spaces as one or both geom
  '* arguments.
  '*
  '* @remarks dSpaceCollide2() is guaranteed to pass all intersecting geom
  '* pairs to the callback function, but may also pass close but
  '* non-intersecting pairs. The number of these calls depends on the
  '* internal algorithms used by the space. Thus you should not expect
  '* that dCollide will return contacts for every pair passed to the
  '* callback.
  '*
  '* @sa dSpaceCollide
  '* @ingroup collide
  '*/
  DECLARE SUB dSpaceCollide2  LIB "ode.dll" ALIAS "dSpaceCollide2" (BYVAL space1 AS dGeomID, BYVAL space2 AS dGeomID, BYREF data as DWORD, BYREF callback AS dNearCallback)


  '/* ************************************************************************ */
  '/* standard classes */

  '/* the maximum number of user classes that are supported */
  global dMaxUserClasses as long = 4


  '/* class numbers - each geometry object needs a unique number */
'  enum {
'  dSphereClass = 0,dBoxClass,dCapsuleClass,dCylinderClass,



'  dPlaneClass,dRayClass,dConvexClass,dGeomTransformClass,



'  dTriMeshClass,dHeightfieldClass,dFirstSpaceClass,



'  dSimpleSpaceClass = dFirstSpaceClass,dHashSpaceClass,dQuadTreeSpaceClass,dLastSpaceClass = dQuadTreeSpaceClass,




'  dFirstUserClass,dLastUserClass = dFirstUserClass + dMaxUserClasses - 1,dGeomNumClasses


'  };


  '/**
  '* @defgroup collide_sphere Sphere Class
  '* @ingroup collide
  '*/

  '/**
  '* @brief Create a sphere geom of the given radius, and return its ID.
  '*
  '* @param space a space to contain the new geom. May be null.
  '* @param radius the radius of the sphere.
  '*
  '* @returns A new sphere geom.
  '*
  '* @remarks The point of reference for a sphere is its center.
  '*
  '* @sa dGeomDestroy
  '* @sa dGeomSphereSetRadius
  '* @ingroup collide_sphere
  '*/
  DECLARE FUNCTION  dCreateSphere  LIB "ode.dll" ALIAS "dCreateSphere" (BYVAL space AS dSpaceID, BYVAL radius AS dReal) AS dGeomID


  '/**
  '* @brief Set the radius of a sphere geom.
  '*
  '* @param sphere the sphere to set.
  '* @param radius the new radius.
  '*
  '* @sa dGeomSphereGetRadius
  '* @ingroup collide_sphere
  '*/
  DECLARE SUB dGeomSphereSetRadius  LIB "ode.dll" ALIAS "dGeomSphereSetRadius" (BYVAL sphere AS dGeomID, BYVAL radius AS dReal)


  '/**
  '* @brief Retrieves the radius of a sphere geom.
  '*
  '* @param sphere the sphere to query.
  '*
  '* @sa dGeomSphereSetRadius
  '* @ingroup collide_sphere
  '*/
  DECLARE FUNCTION  dGeomSphereGetRadius  LIB "ode.dll" ALIAS "dGeomSphereGetRadius" (BYVAL sphere AS dGeomID) AS dReal


  '/**
  '* @brief Calculate the depth of the a given point within a sphere.
  '*
  '* @param sphere the sphere to query.
  '* @param x the X coordinate of the point.
  '* @param y the Y coordinate of the point.
  '* @param z the Z coordinate of the point.
  '*
  '* @returns The depth of the point. Points inside the sphere will have a
  '* positive depth, points outside it will have a negative depth, and points
  '* on the surface will have a depth of zero.
  '*
  '* @ingroup collide_sphere
  '*/
  DECLARE FUNCTION  dGeomSpherePointDepth  LIB "ode.dll" ALIAS "dGeomSpherePointDepth" (BYVAL sphere AS dGeomID, BYVAL x AS dReal, BYVAL y AS dReal, BYVAL z AS dReal) AS dReal


  '--> Convex Functions
  declare function dCreateConvex  LIB "ode.dll" ALIAS "dCreateConvex" (byval space as dSpaceID, byref _planes as dReal, byval _planecount as dword, byref _points dReal, byval _pointcount as dword, byref _polygons as dWORD) as dGeomID

  DECLARE SUB dGeomSetConvex LIB "ode.dll" ALIAS "dGeomSetConvex" ( byval g as dGeomID , byref _planes as dReal, byval _count as dword, byref _points as dReal, byval _pointcount as dword, byref _polygons as dword)
  '<-- Convex Functions

  '/**
  '* @defgroup collide_box Box Class
  '* @ingroup collide
  '*/

  '/**
  '* @brief Create a box geom with the provided side lengths.
  '*
  '* @param space a space to contain the new geom. May be null.
  '* @param lx the length of the box along the X axis
  '* @param ly the length of the box along the Y axis
  '* @param lz the length of the box along the Z axis
  '*
  '* @returns A new box geom.
  '*
  '* @remarks The point of reference for a box is its center.
  '*
  '* @sa dGeomDestroy
  '* @sa dGeomBoxSetLengths
  '* @ingroup collide_box
  '*/
  DECLARE FUNCTION  dCreateBox  LIB "ode.dll" ALIAS "dCreateBox" (BYVAL space AS dSpaceID, BYVAL lx AS dReal, BYVAL ly AS dReal, BYVAL lz AS dReal) AS dGeomID


  '/**
  '* @brief Set the side lengths of the given box.
  '*
  '* @param box the box to set
  '* @param lx the length of the box along the X axis
  '* @param ly the length of the box along the Y axis
  '* @param lz the length of the box along the Z axis
  '*
  '* @sa dGeomBoxGetLengths
  '* @ingroup collide_box
  '*/
  DECLARE SUB dGeomBoxSetLengths  LIB "ode.dll" ALIAS "dGeomBoxSetLengths" (BYVAL box AS dGeomID, BYVAL lx AS dReal, BYVAL ly AS dReal, BYVAL lz AS dReal)


  '/**
  '* @brief Get the side lengths of a box.
  '*
  '* @param box the box to query
  '* @param result the returned side lengths
  '*
  '* @sa dGeomBoxSetLengths
  '* @ingroup collide_box
  '*/
  DECLARE SUB dGeomBoxGetLengths  LIB "ode.dll" ALIAS "dGeomBoxGetLengths" (BYVAL box AS dGeomID, BYVAL result() AS dReal)


  '/**
  '* @brief Return the depth of a point in a box.
  '*
  '* @param box the box to query
  '* @param x the X coordinate of the point to test.
  '* @param y the Y coordinate of the point to test.
  '* @param z the Z coordinate of the point to test.
  '*
  '* @returns The depth of the point. Points inside the box will have a
  '* positive depth, points outside it will have a negative depth, and points
  '* on the surface will have a depth of zero.
  '*/
  DECLARE FUNCTION  dGeomBoxPointDepth  LIB "ode.dll" ALIAS "dGeomBoxPointDepth" (BYVAL box AS dGeomID, BYVAL x AS dReal, BYVAL y AS dReal, BYVAL z AS dReal) AS dReal


  DECLARE FUNCTION  dCreatePlane  LIB "ode.dll" ALIAS "dCreatePlane" (BYVAL space AS dSpaceID, BYVAL a AS dReal, BYVAL b AS dReal, BYVAL c AS dReal, BYVAL d AS dReal) AS dGeomID
  DECLARE SUB dGeomPlaneSetParams  LIB "ode.dll" ALIAS "dGeomPlaneSetParams" (BYVAL plane AS dGeomID, BYVAL a AS dReal, BYVAL b AS dReal, BYVAL c AS dReal, BYVAL d AS dReal)
  DECLARE SUB dGeomPlaneGetParams  LIB "ode.dll" ALIAS "dGeomPlaneGetParams" (BYVAL plane AS dGeomID, BYVAL result() AS dReal)
  DECLARE FUNCTION  dGeomPlanePointDepth  LIB "ode.dll" ALIAS "dGeomPlanePointDepth" (BYVAL plane AS dGeomID, BYVAL x AS dReal, BYVAL y AS dReal, BYVAL z AS dReal) AS dReal

  DECLARE FUNCTION  dCreateCapsule  LIB "ode.dll" ALIAS "dCreateCapsule" (BYVAL space AS dSpaceID, BYVAL radius AS dReal, BYVAL length AS dReal) AS dGeomID
  DECLARE SUB dGeomCapsuleSetParams  LIB "ode.dll" ALIAS "dGeomCapsuleSetParams" (BYVAL ccylinder AS dGeomID, BYVAL radius AS dReal, BYVAL length AS dReal)
  DECLARE SUB dGeomCapsuleGetParams  LIB "ode.dll" ALIAS "dGeomCapsuleGetParams" (BYVAL ccylinder AS dGeomID, BYREF radius AS dReal, BYREF length AS dReal)
  DECLARE FUNCTION  dGeomCapsulePointDepth  LIB "ode.dll" ALIAS "dGeomCapsulePointDepth" (BYVAL ccylinder AS dGeomID, BYVAL x AS dReal, BYVAL y AS dReal, BYVAL z AS dReal) AS dReal

  ' For now we want to have a backwards compatible C-API, note: C++ API is not.
  '#define dCreateCCylinder dCreateCapsule
  '#define dGeomCCylinderSetParams dGeomCapsuleSetParams
  '#define dGeomCCylinderGetParams dGeomCapsuleGetParams
  '#define dGeomCCylinderPointDepth dGeomCapsulePointDepth
  '#define dCCylinderClass dCapsuleClass

  DECLARE FUNCTION  dCreateCylinder  LIB "ode.dll" ALIAS "dCreateCylinder" (BYVAL space AS dSpaceID, BYVAL radius AS dReal, BYVAL length AS dReal) AS dGeomID
  DECLARE SUB dGeomCylinderSetParams  LIB "ode.dll" ALIAS "dGeomCylinderSetParams" (BYVAL cylinder AS dGeomID, BYVAL radius AS dReal, BYVAL length AS dReal)
  DECLARE SUB dGeomCylinderGetParams  LIB "ode.dll" ALIAS "dGeomCylinderGetParams" (BYVAL cylinder AS dGeomID, BYREF radius AS dReal, BYREF length AS dReal)

  DECLARE FUNCTION  dCreateRay  LIB "ode.dll" ALIAS "dCreateRay" (BYVAL space AS dSpaceID, BYVAL length AS dReal) AS dGeomID
  DECLARE SUB dGeomRaySetLength  LIB "ode.dll" ALIAS "dGeomRaySetLength" (BYVAL ray AS dGeomID, BYVAL length AS dReal)
  DECLARE FUNCTION  dGeomRayGetLength  LIB "ode.dll" ALIAS "dGeomRayGetLength" (BYVAL ray AS dGeomID) AS dReal
  DECLARE SUB dGeomRaySet  LIB "ode.dll" ALIAS "dGeomRaySet" (BYVAL ray AS dGeomID, BYVAL px AS dReal, BYVAL py AS dReal, BYVAL pz AS dReal, BYVAL dx AS dReal, BYVAL dy AS dReal, BYVAL dz AS dReal)

  DECLARE SUB dGeomRayGet  LIB "ode.dll" ALIAS "dGeomRayGet" (BYVAL ray AS dGeomID, BYVAL start() AS dReal, BYVAL dir() AS dReal)

  '/*
  '* Set/get ray flags that influence ray collision detection.
  '* These flags are currently only noticed by the trimesh collider, because
  '* they can make a major differences there.
  '*/
  DECLARE SUB dGeomRaySetParams  LIB "ode.dll" ALIAS "dGeomRaySetParams" (BYVAL g AS dGeomID, BYVAL FirstContact AS LONG, BYVAL BackfaceCull AS LONG)
  DECLARE SUB dGeomRayGetParams  LIB "ode.dll" ALIAS "dGeomRayGetParams" (BYVAL g AS dGeomID, BYREF FirstContact AS LONG, BYREF BackfaceCull AS LONG)
  DECLARE SUB dGeomRaySetClosestHit  LIB "ode.dll" ALIAS "dGeomRaySetClosestHit" (BYVAL g AS dGeomID, BYVAL closestHit AS LONG)
  DECLARE FUNCTION  dGeomRayGetClosestHit  LIB "ode.dll" ALIAS "dGeomRayGetClosestHit" (BYVAL g AS dGeomID) AS LONG

  '=============================================================================
  '=                            collision_trimesh.h                            =
  '=============================================================================

  '/*
  '* TriMesh code by Erwin de Vries.
  '*
  '* Trimesh data.
  '* This is where the actual vertexdata (pointers), and BV tree is stored.
  '* Vertices should be single precision!
  '* This should be more sophisticated, so that the user can easyly implement
  '* another collision library, but this is a lot of work, and also costs some
  '* performance because some data has to be copied.
  '*/


  '/*
  '* Data storage for triangle meshes.
  '*/
'  struct dxTriMeshData;
'  typedef struct dxTriMeshData* dTriMeshDataID;

  '/*
  '* These dont make much sense now, but they will later when we add more
  '* features.
  '*/
  DECLARE FUNCTION  dGeomTriMeshDataCreate LIB "ode.dll" ALIAS "dGeomTriMeshDataCreate" () AS dTriMeshDataID
  DECLARE SUB dGeomTriMeshDataDestroy LIB "ode.dll" ALIAS "dGeomTriMeshDataDestroy" (BYVAL g AS dTriMeshDataID)



  'enum { TRIMESH_FACE_NORMALS };
  DECLARE SUB dGeomTriMeshDataSet LIB "ode.dll" ALIAS "dGeomTriMeshDataSet" (BYVAL g AS dTriMeshDataID, BYVAL data_id AS LONG, BYREF in_data AS dword)
  DECLARE SUB dGeomTriMeshDataGet LIB "ode.dll" ALIAS "dGeomTriMeshDataGet" (BYVAL g AS dTriMeshDataID, BYVAL data_id AS LONG)



  '/**
  '* We need to set the last transform after each time step for
  '* accurate collision response. These functions get and set that transform.
  '* It is stored per geom instance, rather than per dTriMeshDataID.
  '*/
  DECLARE SUB dGeomTriMeshSetLastTransform LIB "ode.dll" ALIAS "dGeomTriMeshSetLastTransform" (BYVAL g AS dGeomID, BYVAL last_trans() AS dReal)
  DECLARE FUNCTION dGeomTriMeshGetLastTransform LIB "ode.dll" ALIAS "dGeomTriMeshGetLastTransform" (BYVAL g AS dGeomID) AS dword ' !!! dReal PTR

  '/*
  '* Build TriMesh data with single precision used in vertex data .
  '*/
  DECLARE SUB dGeomTriMeshDataBuildSingle LIB "ode.dll" ALIAS "dGeomTriMeshDataBuildSingle" (BYVAL g AS dTriMeshDataID, BYREF Vertices AS dword, BYVAL VertexStride AS LONG, BYVAL VertexCount AS LONG, BYREF Indices AS dword, BYVAL IndexCount AS LONG, BYVAL TriStride AS LONG)


  '/* same again with a normals array (used as trimesh-trimesh optimization) */
  DECLARE SUB dGeomTriMeshDataBuildSingle1 LIB "ode.dll" ALIAS "dGeomTriMeshDataBuildSingle1" (BYVAL g AS dTriMeshDataID, BYREF Vertices AS dword, BYVAL VertexStride AS LONG, BYVAL VertexCount AS LONG, BYREF Indices AS dword, BYVAL IndexCount AS LONG, BYVAL TriStride AS LONG, BYREF Normals AS dword)



  '/*
  '* Build TriMesh data with double pricision used in vertex data .
  '*/
  DECLARE SUB dGeomTriMeshDataBuildDouble LIB "ode.dll" ALIAS "dGeomTriMeshDataBuildDouble" (BYVAL g AS dTriMeshDataID, BYREF Vertices AS dword, BYVAL VertexStride AS LONG, BYVAL VertexCount AS LONG, BYREF Indices AS dword, BYVAL IndexCount AS LONG, BYVAL TriStride AS LONG)


  '/* same again with a normals array (used as trimesh-trimesh optimization) */
  DECLARE SUB dGeomTriMeshDataBuildDouble1 LIB "ode.dll" ALIAS "dGeomTriMeshDataBuildDouble1" (BYVAL g AS dTriMeshDataID, BYREF Vertices AS dword, BYVAL VertexStride AS LONG, BYVAL VertexCount AS LONG, BYREF Indices AS dword, BYVAL IndexCount AS LONG, BYVAL TriStride AS LONG, BYREF Normals AS dword)




  '/*
  '* Simple build. Single/double precision based on dSINGLE/dDOUBLE!
  '*/
  DECLARE SUB dGeomTriMeshDataBuildSimple LIB "ode.dll" ALIAS "dGeomTriMeshDataBuildSimple" (BYVAL g AS dTriMeshDataID, BYREF Vertices AS dReal, BYVAL VertexCount AS LONG, BYREF Indices AS LONG, BYVAL IndexCount AS LONG)


  '/* same again with a normals array (used as trimesh-trimesh optimization) */
  DECLARE SUB dGeomTriMeshDataBuildSimple1 LIB "ode.dll" ALIAS "dGeomTriMeshDataBuildSimple1" (BYVAL g AS dTriMeshDataID, BYREF Vertices AS dReal, BYVAL VertexCount AS LONG, BYREF Indices AS LONG, BYVAL IndexCount AS LONG, BYREF Normals AS LONG)




  '/* Preprocess the trimesh data to remove mark unnecessary edges and vertices */
  DECLARE SUB dGeomTriMeshDataPreprocess LIB "ode.dll" ALIAS "dGeomTriMeshDataPreprocess" (BYVAL g AS dTriMeshDataID)
  '/* Get and set the internal preprocessed trimesh data buffer, for loading and saving */
  DECLARE SUB dGeomTriMeshDataGetBuffer LIB "ode.dll" ALIAS "dGeomTriMeshDataGetBuffer" (BYVAL g AS dTriMeshDataID, BYREF buf AS dword, BYREF bufLen AS LONG)
  DECLARE SUB dGeomTriMeshDataSetBuffer LIB "ode.dll" ALIAS "dGeomTriMeshDataSetBuffer" (BYVAL g AS dTriMeshDataID, BYREF buf AS dword)


  '/*
  '* Per triangle callback. Allows the user to say if he wants a collision with
  '* a particular triangle.
  '*/
'  DECLARE FUNCTION dTriCallback(byval TriMesh as dGeomID, byval RefObject as dGeomID , byval TriangleIndex as long) as long
  DECLARE SUB dGeomTriMeshSetCallback LIB "ode.dll" ALIAS "dGeomTriMeshSetCallback" (BYVAL g AS dGeomID, BYREF Callback AS dTriCallback)
'  DECLARE FUNCTION dTriCallback dGeomTriMeshGetCallback LIB "ode.dll" ALIAS "dGeomTriMeshGetCallback" (BYVAL g AS dGeomID) AS dTriCallback*

  '/*
  '* Per object callback. Allows the user to get the list of triangles in 1
  '* shot. Maybe we should remove this one.
  '*/
 ' DECLARE FUNCTION dTriCallback(byval TriMesh as dGeomID, byval RefObject as dGeomID , byval TriangleIndex as long) as long  

'  typedef void dTriArrayCallback(dGeomID TriMesh, dGeomID RefObject, int* TriIndices, int TriCount);
  DECLARE SUB dGeomTriMeshSetArrayCallback LIB "ode.dll" ALIAS "dGeomTriMeshSetArrayCallback" (BYVAL g AS dGeomID, BYREF ArrayCallback AS dTriArrayCallback)
  DECLARE FUNCTION dGeomTriMeshGetArrayCallback LIB "ode.dll" ALIAS "dGeomTriMeshGetArrayCallback" (BYVAL g AS dGeomID) AS DWORD'dTriArrayCallback ptr

  '/*
  '* Ray callback.
  '* Allows the user to say if a ray collides with a triangle on barycentric
  '* coords. The user can for example sample a texture with alpha transparency
  '* to determine if a collision should occur.
  '*/
'  typedef int dTriRayCallback(dGeomID TriMesh, dGeomID Ray, int TriangleIndex, dReal u, dReal v);
  DECLARE SUB dGeomTriMeshSetRayCallback LIB "ode.dll" ALIAS "dGeomTriMeshSetRayCallback" (BYVAL g AS dGeomID, BYREF Callback AS dTriRayCallback)
  DECLARE FUNCTION dGeomTriMeshGetRayCallback LIB "ode.dll" ALIAS "dGeomTriMeshGetRayCallback" (BYVAL g AS dGeomID) AS dword 'dTriRayCallback*

  '/*
  '* Trimesh class
  '* Construction. Callbacks are optional.
  '*/
  DECLARE FUNCTION  dCreateTriMesh LIB "ode.dll" ALIAS "dCreateTriMesh" (BYVAL space AS dSpaceID, BYVAL Data AS dTriMeshDataID, BYREF Callback AS dTriCallback, BYREF ArrayCallback AS dTriArrayCallback, BYREF RayCallback AS dTriRayCallback) AS dGeomID

  DECLARE SUB dGeomTriMeshSetData LIB "ode.dll" ALIAS "dGeomTriMeshSetData" (BYVAL g AS dGeomID, BYVAL Data AS dTriMeshDataID)
  DECLARE FUNCTION  dGeomTriMeshGetData LIB "ode.dll" ALIAS "dGeomTriMeshGetData" (BYVAL g AS dGeomID) AS dTriMeshDataID


  ' enable/disable/check temporal coherence
  DECLARE SUB dGeomTriMeshEnableTC LIB "ode.dll" ALIAS "dGeomTriMeshEnableTC" (BYVAL g AS dGeomID, BYVAL geomClass AS LONG, BYVAL enable AS LONG)
  DECLARE FUNCTION  dGeomTriMeshIsTCEnabled LIB "ode.dll" ALIAS "dGeomTriMeshIsTCEnabled" (BYVAL g AS dGeomID, BYVAL geomClass AS LONG) AS LONG

  '/*
  '* Clears the internal temporal coherence caches. When a geom has its
  '* collision checked with a trimesh once, data is stored inside the trimesh.
  '* With large worlds with lots of seperate objects this list could get huge.
  '* We should be able to do this automagically.
  '*/
  DECLARE SUB dGeomTriMeshClearTCCache LIB "ode.dll" ALIAS "dGeomTriMeshClearTCCache" (BYVAL g AS dGeomID)


  '/*
  '* returns the TriMeshDataID
  '*/
  DECLARE FUNCTION  dGeomTriMeshGetTriMeshDataID LIB "ode.dll" ALIAS "dGeomTriMeshGetTriMeshDataID" (BYVAL g AS dGeomID) AS dTriMeshDataID

  '/*
  '* Gets a triangle.
  '*/
  DECLARE SUB dGeomTriMeshGetTriangle LIB "ode.dll" ALIAS "dGeomTriMeshGetTriangle" (BYVAL g AS dGeomID, BYVAL Index AS LONG, BYREF v0() AS dReal, BYREF v1() AS dReal, BYREF v2() AS dReal)

  '/*
  '* Gets the point on the requested triangle and the given barycentric
  '* coordinates.
  '*/
  DECLARE SUB dGeomTriMeshGetPoint LIB "ode.dll" ALIAS "dGeomTriMeshGetPoint" (BYVAL g AS dGeomID, BYVAL Index AS LONG, BYVAL u AS dReal, BYVAL v AS dReal, BYVAL Out() AS dReal)

  '/*

  'This is how the strided data works:

'  type StridedVertex{
'    dVector3 Vertex;
'    ' Userdata
'  };
'  int VertexStride = sizeof(StridedVertex);'
'
'  struct StridedTri{
'    int Indices[3];
'    ' Userdata
'  };
'  int TriStride = sizeof(StridedTri);
'
  '*/


  DECLARE FUNCTION  dGeomTriMeshGetTriangleCount  LIB "ode.dll" ALIAS "dGeomTriMeshGetTriangleCount" (BYVAL g AS dGeomID) AS LONG

  DECLARE SUB dGeomTriMeshDataUpdate LIB "ode.dll" ALIAS "dGeomTriMeshDataUpdate" (BYVAL g AS dTriMeshDataID)


  '=============================================================================
  '=                                collision.h                                = - PART "B"
  '=============================================================================

  DECLARE FUNCTION  dCreateGeomTransform  LIB "ode.dll" ALIAS "dCreateGeomTransform" (BYVAL space AS dSpaceID) AS dGeomID
  DECLARE SUB dGeomTransformSetGeom  LIB "ode.dll" ALIAS "dGeomTransformSetGeom" (BYVAL g AS dGeomID, BYVAL obj AS dGeomID)
  DECLARE FUNCTION  dGeomTransformGetGeom  LIB "ode.dll" ALIAS "dGeomTransformGetGeom" (BYVAL g AS dGeomID) AS dGeomID
  DECLARE SUB dGeomTransformSetCleanup  LIB "ode.dll" ALIAS "dGeomTransformSetCleanup" (BYVAL g AS dGeomID, BYVAL mode AS LONG)
  DECLARE FUNCTION  dGeomTransformGetCleanup  LIB "ode.dll" ALIAS "dGeomTransformGetCleanup" (BYVAL g AS dGeomID) AS LONG
  DECLARE SUB dGeomTransformSetInfo  LIB "ode.dll" ALIAS "dGeomTransformSetInfo" (BYVAL g AS dGeomID, BYVAL mode AS LONG)
  DECLARE FUNCTION  dGeomTransformGetInfo  LIB "ode.dll" ALIAS "dGeomTransformGetInfo" (BYVAL g AS dGeomID) AS LONG


  '/* ************************************************************************ */
  '/* heightfield functions */


  ' Data storage for heightfield data.
  'struct dxHeightfieldData;
  'typedef struct dxHeightfieldData* dHeightfieldDataID;


  '/**
  '* @brief Callback prototype
  '*
  '* Used by the callback heightfield data type to sample a height for a
  '* given cell position.
  '*
  '* @param p_user_data User data specified when creating the dHeightfieldDataID
  '* @param x The index of a sample in the local x axis. It is a value
  '* in the range zero to ( nWidthSamples - 1 ).
  '* @param x The index of a sample in the local z axis. It is a value
  '* in the range zero to ( nDepthSamples - 1 ).
  '*
  '* @return The sample height which is then scaled and offset using the
  '* values specified when the heightfield data was created.
  '*
  '* @ingroup collide
  '*/
  'typedef dReal dHeightfieldGetHeight( void* p_user_data, int x, int z );



  '/**
  '* @brief Creates a heightfield geom.
  '*
  '* Uses the information in the given dHeightfieldDataID to construct
  '* a geom representing a heightfield in a collision space.
  '*
  '* @param space The space to add the geom to.
  '* @param data The dHeightfieldDataID created by dGeomHeightfieldDataCreate and
  '* setup by dGeomHeightfieldDataBuildCallback, dGeomHeightfieldDataBuildByte,* dGeomHeightfieldDataBuildShort or dGeomHeightfieldDataBuildFloat.

  '* @param bPlaceable If non-zero this geom can be transformed in the world using the
  '* usual functions such as dGeomSetPosition and dGeomSetRotation. If the geom is
  '* not set as placeable, then it uses a fixed orientation where the global y axis
  '* represents the dynamic 'height' of the heightfield.
  '*
  '* @return A geom id to reference this geom in other calls.
  '*
  '* @ingroup collide
  '*/
  DECLARE FUNCTION  dCreateHeightfield LIB "ode.dll" ALIAS "dCreateHeightfield" (BYVAL space AS dSpaceID, BYVAL data AS dHeightfieldDataID, BYVAL bPlaceable AS LONG) AS dGeomID



  '/**
  '* @brief Creates a new empty dHeightfieldDataID.
  '*
  '* Allocates a new dHeightfieldDataID and returns it. You must call
  '* dGeomHeightfieldDataDestroy to destroy it after the geom has been removed.
  '* The dHeightfieldDataID value is used when specifying a data format type.
  '*
  '* @return A dHeightfieldDataID for use with dGeomHeightfieldDataBuildCallback,* dGeomHeightfieldDataBuildByte, dGeomHeightfieldDataBuildShort or

  '* dGeomHeightfieldDataBuildFloat.
  '* @ingroup collide
  '*/
  DECLARE FUNCTION  dGeomHeightfieldDataCreate LIB "ode.dll" ALIAS "dGeomHeightfieldDataCreate" (BYVAL ID AS dHeightfieldDataID) AS dHeightfieldDataID


  '/**
  '* @brief Destroys a dHeightfieldDataID.
  '*
  '* Deallocates a given dHeightfieldDataID and all managed resources.
  '*
  '* @param d A dHeightfieldDataID created by dGeomHeightfieldDataCreate
  '* @ingroup collide
  '*/
  DECLARE SUB dGeomHeightfieldDataDestroy LIB "ode.dll" ALIAS "dGeomHeightfieldDataDestroy" (BYVAL d AS dHeightfieldDataID)



  '/**
  '* @brief Configures a dHeightfieldDataID to use a callback to
  '* retrieve height data.
  '*
  '* Before a dHeightfieldDataID can be used by a geom it must be
  '* configured to specify the format of the height data.
  '* This call specifies that the heightfield data is computed by
  '* the user and it should use the given callback when determining
  '* the height of a given element of it's shape.
  '*
  '* @param d A new dHeightfieldDataID created by dGeomHeightfieldDataCreate
  '*
  '* @param width Specifies the total 'width' of the heightfield along
  '* the geom's local x axis.
  '* @param depth Specifies the total 'depth' of the heightfield along
  '* the geom's local z axis.
  '*
  '* @param widthSamples Specifies the number of vertices to sample
  '* along the width of the heightfield. Each vertex has a corresponding
  '* height value which forms the overall shape.
  '* Naturally this value must be at least two or more.
  '* @param depthSamples Specifies the number of vertices to sample
  '* along the depth of the heightfield.
  '*
  '* @param scale A uniform scale applied to all raw height data.
  '* @param offset An offset applied to the scaled height data.
  '*
  '* @param thickness A value subtracted from the lowest height
  '* value which in effect adds an additional cuboid to the base of the
  '* heightfield. This is used to prevent geoms from looping under the
  '* desired terrain and not registering as a collision. Note that the
  '* thickness is not affected by the scale or offset parameters.
  '*
  '* @param bWrap If non-zero the heightfield will infinitely tile in both
  '* directions along the local x and z axes. If zero the heightfield is
  '* bounded from zero to width in the local x axis, and zero to depth in
  '* the local z axis.
  '*
  '* @ingroup collide
  '*/
  DECLARE SUB dGeomHeightfieldDataBuildCallback LIB "ode.dll" ALIAS "dGeomHeightfieldDataBuildCallback" (BYVAL d AS dHeightfieldDataID, BYREF pUserData AS dword, BYREF pCallback AS dHeightfieldGetHeight, BYVAL width AS dReal, BYVAL depth AS dReal, BYVAL widthSamples AS LONG, BYVAL depthSamples AS LONG, BYVAL scale AS dReal, BYVAL offset AS dReal, BYVAL thickness AS dReal, BYVAL bWrap AS LONG)




  '/**
  '* @brief Configures a dHeightfieldDataID to use height data in byte format.
  '*
  '* Before a dHeightfieldDataID can be used by a geom it must be
  '* configured to specify the format of the height data.
  '* This call specifies that the heightfield data is stored as a rectangular
  '* array of bytes (8 bit unsigned) representing the height at each sample point.
  '*
  '* @param d A new dHeightfieldDataID created by dGeomHeightfieldDataCreate
  '*
  '* @param pHeightData A pointer to the height data.
  '* @param bCopyHeightData When non-zero the height data is copied to an
  '* internal store. When zero the height data is accessed by reference and
  '* so must persist throughout the lifetime of the heightfield.
  '*
  '* @param width Specifies the total 'width' of the heightfield along
  '* the geom's local x axis.
  '* @param depth Specifies the total 'depth' of the heightfield along
  '* the geom's local z axis.
  '*
  '* @param widthSamples Specifies the number of vertices to sample
  '* along the width of the heightfield. Each vertex has a corresponding
  '* height value which forms the overall shape.
  '* Naturally this value must be at least two or more.
  '* @param depthSamples Specifies the number of vertices to sample
  '* along the depth of the heightfield.
  '*
  '* @param scale A uniform scale applied to all raw height data.
  '* @param offset An offset applied to the scaled height data.
  '*
  '* @param thickness A value subtracted from the lowest height
  '* value which in effect adds an additional cuboid to the base of the
  '* heightfield. This is used to prevent geoms from looping under the
  '* desired terrain and not registering as a collision. Note that the
  '* thickness is not affected by the scale or offset parameters.
  '*
  '* @param bWrap If non-zero the heightfield will infinitely tile in both
  '* directions along the local x and z axes. If zero the heightfield is
  '* bounded from zero to width in the local x axis, and zero to depth in
  '* the local z axis.
  '*
  '* @ingroup collide
  '*/
  DECLARE SUB dGeomHeightfieldDataBuildByte LIB "ode.dll" ALIAS "dGeomHeightfieldDataBuildByte" (BYVAL d AS dHeightfieldDataID, BYREF pHeightData AS dword, BYVAL bCopyHeightData AS LONG, BYVAL width AS dReal, BYVAL depth AS dReal, BYVAL widthSamples AS LONG, BYVAL depthSamples AS LONG, BYVAL scale AS dReal, BYVAL offset AS dReal, BYVAL thickness AS dReal, BYVAL bWrap AS long)




  '/**
  '* @brief Configures a dHeightfieldDataID to use height data in short format.
  '*
  '* Before a dHeightfieldDataID can be used by a geom it must be
  '* configured to specify the format of the height data.
  '* This call specifies that the heightfield data is stored as a rectangular
  '* array of shorts (16 bit signed) representing the height at each sample point.
  '*
  '* @param d A new dHeightfieldDataID created by dGeomHeightfieldDataCreate
  '*
  '* @param pHeightData A pointer to the height data.
  '* @param bCopyHeightData When non-zero the height data is copied to an
  '* internal store. When zero the height data is accessed by reference and
  '* so must persist throughout the lifetime of the heightfield.
  '*
  '* @param width Specifies the total 'width' of the heightfield along
  '* the geom's local x axis.
  '* @param depth Specifies the total 'depth' of the heightfield along
  '* the geom's local z axis.
  '*
  '* @param widthSamples Specifies the number of vertices to sample
  '* along the width of the heightfield. Each vertex has a corresponding
  '* height value which forms the overall shape.
  '* Naturally this value must be at least two or more.
  '* @param depthSamples Specifies the number of vertices to sample
  '* along the depth of the heightfield.
  '*
  '* @param scale A uniform scale applied to all raw height data.
  '* @param offset An offset applied to the scaled height data.
  '*
  '* @param thickness A value subtracted from the lowest height
  '* value which in effect adds an additional cuboid to the base of the
  '* heightfield. This is used to prevent geoms from looping under the
  '* desired terrain and not registering as a collision. Note that the
  '* thickness is not affected by the scale or offset parameters.
  '*
  '* @param bWrap If non-zero the heightfield will infinitely tile in both
  '* directions along the local x and z axes. If zero the heightfield is
  '* bounded from zero to width in the local x axis, and zero to depth in
  '* the local z axis.
  '*
  '* @ingroup collide
  '*/
  DECLARE SUB dGeomHeightfieldDataBuildShort LIB "ode.dll" ALIAS "dGeomHeightfieldDataBuildShort" (BYVAL d AS dHeightfieldDataID, BYREF pHeightData AS BYTE, BYVAL bCopyHeightData AS LONG, BYVAL width AS dReal, BYVAL depth AS dReal, BYVAL widthSamples AS LONG, BYVAL depthSamples AS LONG, BYVAL scale AS dReal, BYVAL offset AS dReal, BYVAL thickness AS dReal, BYVAL bWrap AS LONG)




  '/**
  '* @brief Configures a dHeightfieldDataID to use height data in
  '* single precision floating point format.
  '*
  '* Before a dHeightfieldDataID can be used by a geom it must be
  '* configured to specify the format of the height data.
  '* This call specifies that the heightfield data is stored as a rectangular
  '* array of single precision floats representing the height at each
  '* sample point.
  '*
  '* @param d A new dHeightfieldDataID created by dGeomHeightfieldDataCreate
  '*
  '* @param pHeightData A pointer to the height data.
  '* @param bCopyHeightData When non-zero the height data is copied to an
  '* internal store. When zero the height data is accessed by reference and
  '* so must persist throughout the lifetime of the heightfield.
  '*
  '* @param width Specifies the total 'width' of the heightfield along
  '* the geom's local x axis.
  '* @param depth Specifies the total 'depth' of the heightfield along
  '* the geom's local z axis.
  '*
  '* @param widthSamples Specifies the number of vertices to sample
  '* along the width of the heightfield. Each vertex has a corresponding
  '* height value which forms the overall shape.
  '* Naturally this value must be at least two or more.
  '* @param depthSamples Specifies the number of vertices to sample
  '* along the depth of the heightfield.
  '*
  '* @param scale A uniform scale applied to all raw height data.
  '* @param offset An offset applied to the scaled height data.
  '*
  '* @param thickness A value subtracted from the lowest height
  '* value which in effect adds an additional cuboid to the base of the
  '* heightfield. This is used to prevent geoms from looping under the
  '* desired terrain and not registering as a collision. Note that the
  '* thickness is not affected by the scale or offset parameters.
  '*
  '* @param bWrap If non-zero the heightfield will infinitely tile in both
  '* directions along the local x and z axes. If zero the heightfield is
  '* bounded from zero to width in the local x axis, and zero to depth in
  '* the local z axis.
  '*
  '* @ingroup collide
  '*/
  DECLARE SUB dGeomHeightfieldDataBuildSingle LIB "ode.dll" ALIAS "dGeomHeightfieldDataBuildSingle" (BYVAL d AS dHeightfieldDataID, BYREF pHeightData AS float, BYVAL bCopyHeightData AS LONG, BYVAL width AS dReal, BYVAL depth AS dReal, BYVAL widthSamples AS LONG, BYVAL depthSamples AS LONG, BYVAL scale AS dReal, BYVAL offset AS dReal, BYVAL thickness AS dReal, BYVAL bWrap AS LONG)




  '/**
  '* @brief Configures a dHeightfieldDataID to use height data in
  '* double precision floating point format.
  '*
  '* Before a dHeightfieldDataID can be used by a geom it must be
  '* configured to specify the format of the height data.
  '* This call specifies that the heightfield data is stored as a rectangular
  '* array of double precision floats representing the height at each
  '* sample point.
  '*
  '* @param d A new dHeightfieldDataID created by dGeomHeightfieldDataCreate
  '*
  '* @param pHeightData A pointer to the height data.
  '* @param bCopyHeightData When non-zero the height data is copied to an
  '* internal store. When zero the height data is accessed by reference and
  '* so must persist throughout the lifetime of the heightfield.
  '*
  '* @param width Specifies the total 'width' of the heightfield along
  '* the geom's local x axis.
  '* @param depth Specifies the total 'depth' of the heightfield along
  '* the geom's local z axis.
  '*
  '* @param widthSamples Specifies the number of vertices to sample
  '* along the width of the heightfield. Each vertex has a corresponding
  '* height value which forms the overall shape.
  '* Naturally this value must be at least two or more.
  '* @param depthSamples Specifies the number of vertices to sample
  '* along the depth of the heightfield.
  '*
  '* @param scale A uniform scale applied to all raw height data.
  '* @param offset An offset applied to the scaled height data.
  '*
  '* @param thickness A value subtracted from the lowest height
  '* value which in effect adds an additional cuboid to the base of the
  '* heightfield. This is used to prevent geoms from looping under the
  '* desired terrain and not registering as a collision. Note that the
  '* thickness is not affected by the scale or offset parameters.
  '*
  '* @param bWrap If non-zero the heightfield will infinitely tile in both
  '* directions along the local x and z axes. If zero the heightfield is
  '* bounded from zero to width in the local x axis, and zero to depth in
  '* the local z axis.
  '*
  '* @ingroup collide
  '*/
  DECLARE SUB dGeomHeightfieldDataBuildDouble LIB "ode.dll" ALIAS "dGeomHeightfieldDataBuildDouble" (BYVAL d AS dHeightfieldDataID, BYREF pHeightData AS double, BYVAL bCopyHeightData AS LONG, BYVAL width AS dReal, BYVAL depth AS dReal, BYVAL widthSamples AS LONG, BYVAL depthSamples AS LONG, BYVAL scale AS dReal, BYVAL offset AS dReal, BYVAL thickness AS dReal, BYVAL bWrap AS LONG)




  '/**
  '* @brief Manually set the minimum and maximum height bounds.
  '*
  '* This call allows you to set explicit min / max values after initial
  '* creation typically for callback heightfields which default to +/- infinity,* or those whose data has changed. This must be set prior to binding with a

  '* geom, as the the AABB is not recomputed after it's first generation.
  '*
  '* @remarks The minimum and maximum values are used to compute the AABB
  '* for the heightfield which is used for early rejection of collisions.
  '* A close fit will yield a more efficient collision check.
  '*
  '* @param d A dHeightfieldDataID created by dGeomHeightfieldDataCreate
  '* @param min_height The new minimum height value. Scale, offset and thickness is then applied.
  '* @param max_height The new maximum height value. Scale and offset is then applied.
  '* @ingroup collide
  '*/
  DECLARE SUB dGeomHeightfieldDataSetBounds LIB "ode.dll" ALIAS "dGeomHeightfieldDataSetBounds" (BYVAL d AS dHeightfieldDataID, BYVAL minHeight AS dReal, BYVAL maxHeight AS dReal)



  '/**
  '* @brief Assigns a dHeightfieldDataID to a heightfield geom.
  '*
  '* Associates the given dHeightfieldDataID with a heightfield geom.
  '* This is done without affecting the GEOM_PLACEABLE flag.
  '*
  '* @param g A geom created by dCreateHeightfield
  '* @param d A dHeightfieldDataID created by dGeomHeightfieldDataCreate
  '* @ingroup collide
  '*/
  DECLARE SUB dGeomHeightfieldSetHeightfieldData LIB "ode.dll" ALIAS "dGeomHeightfieldSetHeightfieldData" (BYVAL g AS dGeomID, BYVAL d AS dHeightfieldDataID)


  '/**
  '* @brief Gets the dHeightfieldDataID bound to a heightfield geom.
  '*
  '* Returns the dHeightfieldDataID associated with a heightfield geom.
  '*
  '* @param g A geom created by dCreateHeightfield
  '* @return The dHeightfieldDataID which may be NULL if none was assigned.
  '* @ingroup collide
  '*/
  DECLARE FUNCTION  dGeomHeightfieldGetHeightfieldData LIB "ode.dll" ALIAS "dGeomHeightfieldGetHeightfieldData" (BYVAL g AS dGeomID) AS dHeightfieldDataID



  '/* ************************************************************************ */
  '/* utility functions */

  DECLARE SUB dClosestLineSegmentPoints  LIB "ode.dll" ALIAS "dClosestLineSegmentPoints" (BYVAL a1() AS dReal, BYVAL a2() AS dReal, BYVAL b1() AS dReal, BYVAL b2() AS dReal, BYVAL cp1() AS dReal, BYVAL cp2() AS dReal)



  DECLARE FUNCTION  dBoxTouchesBox  LIB "ode.dll" ALIAS "dBoxTouchesBox" (BYVAL _p1() AS dReal, BYVAL R1() AS dReal, BYVAL side1() AS dReal, BYVAL _p2() AS dReal, BYVAL R2() AS dReal, BYVAL side2() AS dReal) AS LONG



  declare function dBoxBox LIB "ode.dll" ALIAS "dBoxBox" (byval p1() as dReal, byval r1() as dReal,  BYVAL side1() AS dReal, BYVAL _p2() AS dReal, BYVAL R2() AS dReal, BYVAL side2() AS dReal, byval normal() as dReal, byref depth as dReal, byref return_code as long, byval maxc as long, byref contact as dContactGeom, byval skip as long) as long

  DECLARE SUB dInfiniteAABB  LIB "ode.dll" ALIAS "dInfiniteAABB" (BYVAL geom AS dGeomID, BYVAL aabb() AS dReal)
  DECLARE SUB dInitODE LIB "ode.dll" ALIAS "dInitODE" ()
  DECLARE SUB dCloseODE LIB "ode.dll" ALIAS "dCloseODE" ()

  '/* ************************************************************************ */
  '/* custom classes */

'  typedef void dGetAABBFn (dGeomID, dReal aabb[6]);
'  typedef int dColliderFn (dGeomID o1, dGeomID o2,int flags, dContactGeom *contact, int skip);

'  typedef dColliderFn * dGetColliderFnFn (int num);
'  typedef void dGeomDtorFn (dGeomID o);
'  typedef int dAABBTestFn (dGeomID o1, dGeomID o2, dReal aabb[6]);

  TYPE dGeomClass
     bytes     AS LONG
     collider  AS DWORD
     aabb      AS DWORD
     aabb_test AS DWORD
     dtor      AS DWORD
  END TYPE
  
  DECLARE FUNCTION  dCreateGeomClass  LIB "ode.dll" ALIAS "dCreateGeomClass" (BYREF classptr AS dGeomClass) AS LONG
  DECLARE FUNCTION  dGeomGetClassData  LIB "ode.dll" ALIAS "dGeomGetClassData" (BYVAL dGeomIDlike AS dGeomID) as dword
  DECLARE FUNCTION  dCreateGeom  LIB "ode.dll" ALIAS "dCreateGeom" (BYVAL classnum AS LONG) AS dGeomID

  '/* ************************************************************************ */
