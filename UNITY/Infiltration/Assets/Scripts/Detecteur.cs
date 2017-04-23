using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Detecteur : MonoBehaviour {

	public	BigBoss	patron;
	public	string	Atag;

	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
		
	}

	void	OnTriggerEnter(Collider col) {
		if (col.gameObject.CompareTag (Atag))
			patron.see = true;
	}
	void	OnTriggerExit(Collider col) {
		patron.see = false;
	}

}
