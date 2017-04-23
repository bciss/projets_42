using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Key : MonoBehaviour {

	public	GuyControlleur	Guy;
	public	string			Atag;
	public	AudioSource		bip;
	public	GameObject		lol;
	// Use this for initialization
	void	Start () {
		
	}
	
	// Update is called once per frame
	void	Update () {
		
	}

	void	OnTriggerEnter(Collider col) {
		if (col.CompareTag (Atag)) {
			Guy.key = true;
			bip.Play ();
			lol.gameObject.SetActive (false);
		}
	}
}
