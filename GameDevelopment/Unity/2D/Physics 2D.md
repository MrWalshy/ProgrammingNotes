Unity 4.3 included a 2D physics system to make 2D game development easier. Before this, the physics had to be created by the developer or faked using 3D physics. Specifically, the **RidgidBody2D** component is used to add 2D physics to objects using colliders, physics materials, effectors, and joints.

To make a 2D object join the physics system, add the **RidgidBody2D** component to it. Automatically, this will apply the gravity effect. To add collision capabilities, add a 2D collider like the **Box Collider 2D** or **Polygon Collider 2D**, this prevents object passing through each other by default.

Applying physics materials using the **Physics Material 2D** component allows for enhanced control over physics interactions, like the friction and bounciness of an object.

To apply a force to a 2D object, **effector** components can be added. Unity 5 added four effector components:

- AreaEffector2D
- PointEffector2D
- PlatformEffector2D
- SurfaceEffector2D

Unity 5.3 further added a **BuoyanceEffector2D** and a **ConstantForce2D** effector was also added for applying a constant force to a sprite.

**Joints** can also be added to allow joining various 2D game object together, some of which include:

- DistanceJoint2D
- FixedJoint2D
- FrictionJoint2D
- HingeJoint2D
- RelativeJoint2D
- SliderJoint2D
- SpringJoint2D
- TargetJoint2D
- WheelJoint2D