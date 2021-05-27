#include <tree.h>
#include <gtest.h>

TEST(bintree, can_create_bintree)
{
	ASSERT_NO_THROW(Bintree<int> *a = new Bintree<int>());
}

TEST(bintree, proverka_FindKey_if_key_est)
{
	Bintree<int> *a = new Bintree<int>();
	Node<int> *b = new Node<int>();
	b->key = 6;
	a->Insert(a->root, b);
	b->key = 2;
	a->Insert(a->root, b);
	b->key = 8;
	a->Insert(a->root, b);
	b->key = 0;
	a->Insert(a->root, b);
	b = a->Findkey(a->root, 2);
	EXPECT_EQ(b->key, 2);
}

TEST(bintree, any_throw_if_FindKey_havent_key)
{
	Bintree<int> *a = new Bintree<int>();
	Node<int> *b = new Node<int>();
	b->key = 6;
	a->Insert(a->root, b);
	b->key = 2;
	a->Insert(a->root, b);
	b->key = 8;
	a->Insert(a->root, b);
	b->key = 0;
	a->Insert(a->root, b);
	ASSERT_ANY_THROW(a->Findkey(a->root, 10));
}

TEST(bintree, can_FindMin)
{
	Bintree<int> *a = new Bintree<int>();
	Node<int> *b = new Node<int>();
	b->key = 9;
	a->Insert(a->root, b);
	b->key = 6;
	a->Insert(a->root, b);
	b->key = 8;
	a->Insert(a->root, b);
	b->key = 2;
	a->Insert(a->root, b);
	b->key = 4;
	a->Insert(a->root, b);
	b->key = 0;
	a->Insert(a->root, b);
	b->key = 5;
	a->Insert(a->root, b);
	b->key = 1;
	a->Insert(a->root, b);
	b->key = 7;
	a->Insert(a->root, b);
	Node<int> *c = a->FindMin(a->root);
	EXPECT_EQ(c->key, 0);
}

TEST(bintree, throw_if_in_FindMin_empty_tree)
{
	Bintree<int> *a = new Bintree<int>();
	ASSERT_ANY_THROW(a->FindMin(a->root));
}

TEST(bintree, can_FindMax)
{
	Bintree<int> *a = new Bintree<int>();
	Node<int> *b = new Node<int>();
	b->key = 9;
	a->Insert(a->root, b);
	b->key = 6;
	a->Insert(a->root, b);
	b->key = 8;
	a->Insert(a->root, b);
	b->key = 2;
	a->Insert(a->root, b);
	b->key = 4;
	a->Insert(a->root, b);
	b->key = 0;
	a->Insert(a->root, b);
	b->key = 5;
	a->Insert(a->root, b);
	b->key = 1;
	a->Insert(a->root, b);
	b->key = 7;
	a->Insert(a->root, b);
	Node<int> *c = a->FindMax(a->root);
	EXPECT_EQ(c->key, 9);
}

TEST(bintree, throw_if_in_FindMax_empty_tree)
{
	Bintree<int> *a = new Bintree<int>();
	ASSERT_ANY_THROW(a->FindMax(a->root));
}

TEST(bintree, can_FindNext)
{
	Bintree<int> *a = new Bintree<int>();
	Node<int> *b = new Node<int>();
	b->key = 9;
	a->Insert(a->root, b);
	b->key = 6;
	a->Insert(a->root, b);
	b->key = 8;
	a->Insert(a->root, b);
	b->key = 2;
	a->Insert(a->root, b);
	b->key = 4;
	a->Insert(a->root, b);
	b->key = 0;
	a->Insert(a->root, b);
	b->key = 5;
	a->Insert(a->root, b);
	b->key = 1;
	a->Insert(a->root, b);
	b->key = 7;
	a->Insert(a->root, b);
	b->key = 6;
	Node<int> *c = a->FindNext(a->root, b);
	EXPECT_EQ(c->key, 7);
}