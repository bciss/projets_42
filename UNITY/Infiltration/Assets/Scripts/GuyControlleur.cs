using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class GuyControlleur : MonoBehaviour {

	// Use this for initialization
	public	float 		speed = 6.0F;
	public	float 		jumpSpeed = 8.0F;
	public	float		gravity = 20.0F;
	private float       rotY = 0.0f;
	private float       rotX = 0.0f;
	public  float       mouseSensitivity = 100.0f;
	public  float       clampAngle = 80.0f;
	public	AudioSource	jumpSound;
	public	bool 		key;
	public	bool 		end;
	public	Text 		txt;
	public	AudioSource	Sound;
	public	AudioSource	loseSound;
	public	AudioSource	panic;
	private	bool 		first = true;
	private	bool 		firsty = true;
	private	bool 		b = false;
	private	Text		t;
	public	Camera		camera;
	public	BigBoss		patron;

	private Vector3 moveDirection = Vector3.zero;

	void	Start() {
		Vector3 rot = transform.localRotation.eulerAngles;
		rotY = rot.y;
		rotX = rot.x;
		key = false;
		t = txt.GetComponent<Text> ();
		Cursor.lockState = CursorLockMode.Locked;
//		t.color = new Color(255, 44, 144, 0);

	}
	void Update() {
		if (!end)
			Move ();
		else if (end && first) { ///////////////////
			StartCoroutine (Lose ());
			first = false;
		}
		if (patron.suspicion >= 150 && firsty) {
			Sound.Stop ();
			panic.Play ();
			firsty = false;
		} else if (firsty == false && patron.suspicion < 150) {
			Sound.Play ();
			panic.Stop ();
			firsty = true;
		}
	}

	IEnumerator	Lose () {
		sptext("YOU'LL NEVER FIND THE TRUTH");
		Sound.Stop ();
		panic.Stop ();
		loseSound.Play ();
		yield return new WaitForSeconds (5f);
		SceneManager.LoadScene (SceneManager.GetActiveScene ().name);
	}

	private	void Move() {
		CharacterController controller = GetComponent<CharacterController>();
		if (controller.isGrounded) {
			moveDirection = new Vector3(Input.GetAxis("Vertical") * -1f, 0, Input.GetAxis("Horizontal"));
			moveDirection = transform.TransformDirection(moveDirection);
			moveDirection *= speed;
			if (Input.GetButton ("Jump")) {
				moveDirection.y = jumpSpeed;
				jumpSound.Play ();
			}

		}
		if (!end) {
			moveDirection.y -= gravity * Time.deltaTime;
			controller.Move (moveDirection * Time.deltaTime);
		}
		float mouseX = Input.GetAxis ("Mouse X");
		float mouseY = -Input.GetAxis ("Mouse Y");

		rotY += mouseX * mouseSensitivity * Time.deltaTime;
		rotX += mouseY * mouseSensitivity * Time.deltaTime;

		rotX = Mathf.Clamp (rotX, -clampAngle, clampAngle);

		transform.Rotate (Vector3.up * mouseX * mouseSensitivity * Time.deltaTime);
		camera.transform.rotation = Quaternion.Euler(rotX, transform.eulerAngles.y - 90, 0);
	}

	public IEnumerator FadeTextToFullAlpha(float t, Text i)
	{
		i.color = new Color(i.color.r, i.color.g, i.color.b, 0);
		while (i.color.a < 1.0f)
		{
			i.color = new Color(i.color.r, i.color.g, i.color.b, i.color.a + 0.01f);
			yield return new WaitForSeconds(t);
		}
	}

	public IEnumerator FadeTextToZeroAlpha(float t, Text i)
	{
		i.color = new Color(i.color.r, i.color.g, i.color.b, 1);
		while (i.color.a > 0.0f)
		{
			i.color = new Color(i.color.r, i.color.g, i.color.b, i.color.a - 0.01f);
			yield return new WaitForSeconds(t);
		}
	}

	IEnumerator re()
	{
		yield return new WaitForSeconds(3);
		b = false;
		StartCoroutine (FadeTextToZeroAlpha(0.001f, t));
	}

	public void sptext(string s)
	{
		t.text = s;
		b = true;
		StartCoroutine (FadeTextToFullAlpha (0.001f, t));
		StartCoroutine (re ());
	}

	void	OnTriggerEnter(Collider col) {
		if (col.CompareTag("Finish"))
			StartCoroutine (endgame());
	}

	IEnumerator	endgame () {
		yield return new WaitForSeconds (5f);
		sptext("NOW YOU KNOW THE TRUTH");
		yield return new WaitForSeconds (5f);
		SceneManager.LoadScene (SceneManager.GetActiveScene ().name);
	}
}
