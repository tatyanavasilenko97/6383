#pragma once
namespace binTree_modul
{
	typedef char base;
	struct node {
		base info;
		node *lt;
		node *rt;
		// constructor
		node() { lt = NULL; rt = NULL; }
	};

	typedef node *binTree; // "представитель" бинарного дерева
	binTree Create(void);
	bool isNull(binTree);
	bool RooBT(binTree);
	base RootBT(binTree); // для непустого бин.дерева
	binTree Left(binTree);// для непустого бин.дерева
	binTree Right(binTree);// для непустого бин.дерева
	binTree ConsBT(const base &x, binTree &lst, binTree &rst);
	void destroy(binTree&);

} // end of namespace binTree_modul

  /*
  1) RootBT: NonNullBT -> ?;
  2) Left: NonNullBT -> BT;
  3) Right: NonNullBT -> BT;
  4) ConsBT: ? * BT * BT -> NonNullBT;
  5) Null: BT -> Boolean;
  6) Create:  -> BT

  */
