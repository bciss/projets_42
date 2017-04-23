using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class smoke : MonoBehaviour {

	public	GameObject	Smoke;
	public	BigBoss		patron;
	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
		
	}

	void	OnTriggerStay(Collider col) {
		if (col.CompareTag ("Guy") && Input.GetKeyDown ("e")) {
			Smoke.SetActive (true);
			patron.brouille = true;
		}
	}
}
