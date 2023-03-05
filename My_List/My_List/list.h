#pragma once

namespace My_List
{
	//����ṹ
	template<class T>
	struct __list_node
	{
		__list_node<T>* _next;
		__list_node<T>* _prev;
		T _data;

		//����
		__list_node(const T x = T())
			:_data(x)
			,_next(nullptr)
			,_prev(nullptr)
		{}
	};

	//������ָ��ṹ
	template<class T>
	struct __list_iterator
	{
		//����������Ϊ����ڵ��ַ
		typedef __list_node<T> Node;
		Node* _node;

		//����
		__list_iterator(Node* node)
			:_node(node)
		{}

		T& operator*()
		{
			return _node->_data;
		}

		//ǰ��++
		__list_iterator<T>& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		//����++
		__list_iterator<T> operator++(int)
		{
			__list_iterator<T> tmp(*this);
			++(*this);

			return tmp;
		}

		//ǰ��--
		__list_iterator<T>& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		//����--
		__list_iterator<T> operator--(int)
		{
			__list_iterator<T> tmp(*this);
			--(*this);

			return tmp;
		}

		bool operator!=(const __list_iterator<T>& it)
		{
			return _node != it._node;
		}

		bool operator==(const __list_iterator<T>& it)
		{
			return _node == it._node;
		}

		//->
		T* operator->()
		{
			return &_node->_data;
		}

	};


	template<class T>
	class list
	{
		typedef __list_node<T> Node;
	public:
		typedef __list_iterator<T> iterator;

		//����
		list()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		//�����������
		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				erase(it++);
			}
		}

		//ɾ���м�ڵ�
		void erase(iterator it)
		{
			Node* tmp = it._node->_prev;
			tmp->_next = it._node->_next;
			it._node->_next->_prev = tmp;
			delete it._node;
			it._node = nullptr;
		}

		iterator begin()
		{
			return iterator(_head->_next);
		}

		iterator end()
		{
			return iterator(_head);
		}


		//β��
		void push_back(const T& x)
		{
			Node* tail = _head->_prev;
			Node* newnode = new Node(x);

			newnode->_next = _head;
			newnode->_prev = tail;
			tail->_next = newnode;
			_head->_prev = newnode;
		}

		
	private:
		Node* _head;
	};







}