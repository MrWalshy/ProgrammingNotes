## 2D
### Moving left and right
```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerMovement : MonoBehaviour
{
    [SerializeField] private float speed = 5f;

    private Rigidbody2D rigidBody;
    private SpriteRenderer spriteRenderer;

    private void Awake()
    {
        rigidBody = GetComponent<Rigidbody2D>();
        spriteRenderer = GetComponent<SpriteRenderer>();
    }

    // for physics calculations
    private void FixedUpdate()
    {
        PlayerWalk();
    }

    void PlayerWalk()
    {
        float horizontalInput = Input.GetAxisRaw("Horizontal"); // GetAxis is decimal between -1 and 1, GetAxisRaw is -1, 0, or 1
        Debug.Log("Horizontal input: " + horizontalInput);

        if (horizontalInput > 0)
        {
            rigidBody.velocity = new Vector2(speed, rigidBody.velocity.y);
            spriteRenderer.flipX = false; // face right
        }
        else if (horizontalInput < 0)
        {
            rigidBody.velocity = new Vector2(-speed, rigidBody.velocity.y);
            spriteRenderer.flipX = true; // face left
        }
        else rigidBody.velocity = new Vector2(0,rigidBody.velocity.y);
    }
}

```

First, the player horizontal input (left and right keys) is retrieved with `Input.GetAxis` or `Input.GetAxisRaw`.

- Input of `0` means the player is not moving
- Input less than `0` means the player is moving left
- Input greater than `0` means the player is moving right

The game objects `RigidBody2D` is then accessed to adjust the velocity of the player using the `speed` field as an argument to the `Vector2` constructor. The `SpriteRenderer` is utilised to flip the sprite on its `X` axis based on whether the player is going left or right.

### Jumping
To allow the player to jump, it needs to be detected whether the player is on the ground or not. To do this, ray casting can be utilised to check if the player is touching the ground or not:

```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerMovement : MonoBehaviour
{
    [SerializeField] private GameObject groundLayerPosition;
    [SerializeField] private LayerMask groundLayerMask;

    private Rigidbody2D rigidBody;

    private bool isOnGround;
    private bool isJumping;
    [SerializeField] private float jumpPower = 10f;

    private void Awake()
    {
        rigidBody = GetComponent<Rigidbody2D>();
    }

    // for physics calculations
    private void FixedUpdate()
    {
	    IsPlayerOnGround();
        PlayerJump();
    }

    bool IsPlayerOnGround()
    {
        isOnGround = Physics2D.Raycast(groundLayerPosition.transform.position, Vector2.down, 0.1f, groundLayerMask);

        if (isOnGround && isJumping) // if jump just ended
        {
            isJumping = false;
        }

        return isOnGround;
    }

    void PlayerJump()
    {
        if (isOnGround && Input.GetKey(KeyCode.Space))
        {
            isJumping = true;
            rigidBody.velocity = new Vector2(rigidBody.velocity.x, jumpPower);
        }
    }
}

```

The `groundLayerPosition` is the ground game object to check against, the `groundLayerMask` is a layer that can be assigned to game objects.