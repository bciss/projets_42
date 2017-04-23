﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;

public class zombie_controller : MonoBehaviour {

	perso 				maya;
	Maya_Controlleur  maya2;
	NavMeshAgent		navmeshAgent;
	bool 				dead = false;
	Animator			animator;
	perso				stat;
	float				timeattack = 0;
	public int					level;
	public	GameObject	PopoPrefab;
	public	Weapon_pool	weaponpool;
	// Use this for initialization
	void Start () {
		navmeshAgent = GetComponent< NavMeshAgent > ();
		animator = GetComponent< Animator > ();
		stat = GetComponent< perso> ();
		maya2 = GameObject.FindGameObjectWithTag ("Player").GetComponent<Maya_Controlleur>();
		UpdateStat ();
	}
	
	// Update is called once per frame
	void Update () {
		if (dead)
			return;
		if (maya != null && Vector3.Distance (maya.transform.position, transform.position) > 5)
			navmeshAgent.destination = maya.transform.position;
		if (maya != null && Vector3.Distance (maya.transform.position, transform.position) <= 5) {
			navmeshAgent.destination = transform.position;
			transform.LookAt (maya.transform.position);
		}

		if (maya != null && navmeshAgent.remainingDistance <= 5)
		{
			timeattack += Time.deltaTime;
			if (timeattack > 0.35) {
				stat.attack(maya);
				timeattack = 0;
			}
		}

		animator.SetBool ("attack", (maya != null && navmeshAgent.remainingDistance <= 5));
		animator.SetBool ("run", navmeshAgent.remainingDistance > 5);
		CheckDeath ();
	}

//	bool randomboolean = false;

	void	UpdateStat() {
//		if (randomboolean)
		level = maya2.stat.level; ///////////////////////////////////////////////////////**************************************************************************************************************************************************************
//		randomboolean = true;
		Debug.Log ("fdsf" + level);	
		int	i = level - 1;
		stat.STR += stat.STR / 100 * i;
		stat.AGI += stat.AGI / 100 * i;
		stat.CON += stat.CON / 100 * i;
		stat.statupdate ();
		stat.HP = stat.MaxHP;
	}

	void OnTriggerEnter(Collider c)
	{
		if (c.tag == "Player")
			maya = c.gameObject.GetComponent<perso>();
	}

	private	void	CheckDeath() {
		if (stat.HP <= 0 && dead == false) {
			animator.SetTrigger ("dead");
			dead = true;
			StartCoroutine (disparition());
			GameState.mayaController.stat.xp += 40 + (20 * (level - 1));
			GameState.mayaController.stat.money += 1 + (20 * (level - 1));
		}
	}

	IEnumerator disparition()
	{
		int k = Random.Range (1, 10);
		Debug.Log (k);
		if (Random.Range (1, 11) > 7)
			Instantiate (PopoPrefab, transform.position, transform.rotation);
		else if (Random.Range (1, 11) > 9) {
			Weapon inst = Instantiate (weaponpool.weapons [Random.Range (0, weaponpool.weapons.Count)], transform.position, transform.rotation);
			inst.transform.localScale = new Vector3 (1f, 1f, 1f);
		}
		GetComponent<CapsuleCollider> ().enabled = false;
		GameObject.Destroy (navmeshAgent);
		yield return new WaitForSeconds (2f);
		yield return new WaitForSeconds (0.1f);
		transform.position -= new Vector3 (0, 0.06f, 0);
		yield return new WaitForSeconds (0.1f);
		transform.position -= new Vector3 (0, 0.06f, 0);
		yield return new WaitForSeconds (0.1f);
		transform.position -= new Vector3 (0, 0.06f, 0);
		yield return new WaitForSeconds (0.1f);
		transform.position -= new Vector3 (0, 0.06f, 0);
		yield return new WaitForSeconds (0.1f);
		transform.position -= new Vector3 (0, 0.06f, 0);
		yield return new WaitForSeconds (0.1f);
		transform.position -= new Vector3 (0, 0.06f, 0);
		yield return new WaitForSeconds (0.1f);
		transform.position -= new Vector3 (0, 0.06f, 0);
		yield return new WaitForSeconds (0.1f);
		transform.position -= new Vector3 (0, 0.06f, 0);
		yield return new WaitForSeconds (0.1f);
		transform.position -= new Vector3 (0, 0.06f, 0);
		yield return new WaitForSeconds (0.1f);
		transform.position -= new Vector3 (0, 0.06f, 0);
		yield return new WaitForSeconds (0.1f);
		transform.position -= new Vector3 (0, 0.06f, 0);
		yield return new WaitForSeconds (0.1f);
		transform.position -= new Vector3 (0, 0.06f, 0);
		yield return new WaitForSeconds (0.1f);
		transform.position -= new Vector3 (0, 0.06f, 0);
		yield return new WaitForSeconds (0.1f);
		transform.position -= new Vector3 (0, 0.06f, 0);
		yield return new WaitForSeconds (0.1f);
		transform.position -= new Vector3 (0, 0.06f, 0);
		yield return new WaitForSeconds (0.1f);
		transform.position -= new Vector3 (0, 0.06f, 0);
		yield return new WaitForSeconds (0.1f);
		transform.position -= new Vector3 (0, 0.06f, 0);
		yield return new WaitForSeconds (0.1f);
		transform.position -= new Vector3 (0, 0.06f, 0);
		yield return new WaitForSeconds (0.1f);
		transform.position -= new Vector3 (0, 0.06f, 0);
		yield return new WaitForSeconds (0.1f);
		transform.position -= new Vector3 (0, 0.06f, 0);
		yield return new WaitForSeconds (0.1f);
		transform.position -= new Vector3 (0, 0.06f, 0);
		GameObject.Destroy (gameObject);
	}
}