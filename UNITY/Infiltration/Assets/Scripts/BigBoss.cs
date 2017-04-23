using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class BigBoss : MonoBehaviour {

	public	bool			see;
	public	float			suspicion = 0;
	public	AudioSource		alert;
	public	Slider			slide;
	private	bool 			vue;
	public	bool			brouille;
	public	GuyControlleur	Guy;
	// Use this for initialization
	void Start () {
		vue = false;
		brouille = false;
	}
	
	// Update is called once per frame
	void Update () {
		if (see == true && suspicion < 200)
			suspicion += (brouille) ? 3 : 15;
		if (suspicion >= 200 & vue == false) {
			Alert ();
			Guy.end = true;
			vue = true;
		}
		if (suspicion > 0)
			suspicion--;
//		Debug.Log (suspicion);
		slide.value = suspicion;

//	public	void	SeeSomething() {
//	}
	}
	public	void	Alert() {
		alert.Play ();
		Debug.Log("Tmort");
	}
}
