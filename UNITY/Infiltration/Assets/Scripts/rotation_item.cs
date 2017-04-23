using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class rotation_item : MonoBehaviour {


	public	float	min = -1;
	public	float	max = -1;
	public	float	speed;
	// Use this for initialization
	void Start () {
	}
	
	// Update is called once per frame
	void Update () {
		if (min == -1 && max == -1) {
			transform.Rotate (Vector3.up * Time.deltaTime * speed, Space.World);
		} else {
//			Debug.Log (transform.rotation.y * 360);
			if (transform.rotation.y * 360 < min || transform.rotation.y * 360 > max) {
				speed *= -1;
			}
			transform.Rotate (Vector3.up * Time.deltaTime * -speed, Space.World);
		}
	}
}
