#pragma once
namespace bin_tree
{
	template <class T> struct b_node
	{
		b_node()
		{
			l_br = r_br = 0;
		};

		T data;
		b_node<T> * l_br;
		b_node<T> * r_br;

	};

	template <class T> b_node<T> * create_bt()
	{
		return 0;
	}

	template <class T> bool is_null_bt(b_node<T> * bt)
	{
		bool res = false;
		if (bt == 0x0)
			res = true;
		return res;
	}

	template <class T> b_node<T> * cons_bt(b_node<T> * bt1, b_node<T> * bt2, T root)
	{
		if (!(is_null_bt<T>(bt1) && is_null_bt<T>(bt2)))
		{
			b_node<T> * new_bt = new b_node<T>();
			new_bt->l_br = bt1;
			new_bt->r_br = bt2;
			new_bt->data = root;
			return new_bt;
		}
		else
			return 0;
	}

	template <class T> void destroy_bt(b_node<T> * bt)
	{
		if (!is_null_bt(bt))
		{
			destroy_bt(get_l_br(bt));
			destroy_bt(get_r_br(bt));
			delete bt;
		}
	}

	template <class T> b_node<T> * make_root(T t_data)
	{
		b_node<T> * new_bt = new b_node<T>();
		new_bt->data = t_data;
		new_bt->l_br = 0;
		new_bt->r_br = 0;
		return new_bt;
	}
};