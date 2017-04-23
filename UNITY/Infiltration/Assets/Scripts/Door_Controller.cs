using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Door_Controller : MonoBehaviour {

	public	Text		findkey;
	public	GameObject	door;
	private bool		open;
	public	Vector3 targetPosition;
	public	Vector3 increaseValues;
	public	AudioSource	unlock;
	public GuyControlleur	Guy;

	// Use this for initialization
	void Start () {
		open = false;
	}

	// Update is called once per frame
	void Update () {
		if (open == true) {
			if (Vector3.Distance (targetPosition, transform.position) > 0.2f)
				door.transform.localPosition += increaseValues * Time.deltaTime;
		}
	}

	void OnTriggerStay (Collider col) {
		if (col.CompareTag ("Guy") && Input.GetKeyDown ("e")) {
			if (open == false && Guy.key == false) {
				findkey.text = "You need a key to acces this place";
				StartCoroutine (twosecmsg(findkey));
			} else if (open == false) {
				open = true;
				unlock.Play ();
			}
		}
	}

	IEnumerator	twosecmsg(Text txt) {
		yield return new WaitForSeconds (2f);
		txt.text = "";
	}
}
