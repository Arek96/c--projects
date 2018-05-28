#include "stdafx.h"
#include "CppUnitTest.h"
#define private public 
#include "CList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(test1_konstruktor)
		{
			CList test;

			Assert::AreEqual((size_t)0, test.count);
			Assert::IsNull(test.first);
		}

		TEST_METHOD(test2_size)
		{
			CList test;

			Assert::AreEqual((size_t)0, test.count);
			Assert::IsNull(test.first);

			point_t p;

			for (size_t i = 0; i <= 15; i++)
			{
				p.x = i;
				p.y = 2 * i;
				p.z = 3 + i;
				test.push_back(p);
			}

			Assert::AreEqual(test.count, test.size());
		}

		TEST_METHOD(test3_pushback)
		{
			CList test;

			Assert::AreEqual((size_t)0, test.count);
			Assert::IsNull(test.first);

			point_t p, p2;

			p.x = 1;
			p.y = 2;
			p.z = 3;
			test.push_back(p);													

			Assert::AreEqual((size_t)1, test.count);
			Assert::IsNull(test.first->next);
			Assert::AreEqual(test.first->p.x, p.x);
			Assert::AreEqual(test.first->p.y, p.y);
			Assert::AreEqual(test.first->p.z, p.z);

			p2.x = 14;
			p2.y = 22;
			p2.z = 13;
			test.push_back(p2);													

			list_el *second = test.first->next;

			Assert::AreEqual((size_t)2, test.count);
			Assert::AreEqual(test.first->p.x, p.x);
			Assert::AreEqual(test.first->p.y, p.y);
			Assert::AreEqual(test.first->p.z, p.z);
			Assert::IsNull(second->next);
			Assert::AreEqual(second->p.x, p2.x);
			Assert::AreEqual(second->p.y, p2.y);
			Assert::AreEqual(second->p.z, p2.z);
		}

		TEST_METHOD(test4_popback)
		{
			CList test;

			int x = 0;

			Assert::AreEqual((size_t)0, test.count);
			Assert::IsNull(test.first);

			if (test.pop_back() == res_error)									
			{
				x = 1;
			}

			Assert::AreEqual(1, x);

			x = 0;

			point_t p, p2;

			p.x = 1;
			p.y = 2;
			p.z = 3;
			test.push_back(p);													

			if (test.pop_back() == res_ok)
			{
				x = 1;
			}

			Assert::AreEqual((size_t)0, test.count);
			Assert::IsNull(test.first);
			Assert::AreEqual(1, x);

			x = 0;

			p.x = 1;
			p.y = 2;
			p.z = 3;
			test.push_back(p);													
			p2.x = 14;
			p2.y = 22;
			p2.z = 13;
			test.push_back(p2);

			if (test.pop_back() == res_ok)
			{
				x = 1;
			}

			Assert::AreEqual(1, x);
			x = 0;

			Assert::AreEqual((size_t)1, test.count);
			Assert::IsNull(test.first->next);
			Assert::AreEqual(test.first->p.x, p.x);
			Assert::AreEqual(test.first->p.y, p.y);
			Assert::AreEqual(test.first->p.z, p.z);

			if (test.pop_back() == res_ok)
			{
				x = 1;
			}

			Assert::AreEqual(1, x);
			Assert::AreEqual((size_t)0, test.count);
			Assert::IsNull(test.first);
		}

		TEST_METHOD(test5_get)
		{
			CList test;

			Assert::AreEqual((size_t)0, test.count);
			Assert::IsNull(test.first);

			point_t p, p2, p3, pp;

			int x = 0;

			if (test.get(0, pp) == res_error)											
			{
				x = 1;
			}

			Assert::AreEqual(x, 1);
			x = 0;

			if (test.get(5, pp) == res_error)								
			{
				x = 1;
			}

			Assert::AreEqual(x, 1);
			x = 0;

			for (int i = 0; i <= 10; i++)
			{
				p.x = i;
				p.y = 2 * i;
				p.z = 3 + i*i;
				test.push_back(p);
				if (i == 3)
				{
					p2 = p;
				}
				if (i == 9)
				{
					p3 = p;
				}
			}

			if (test.get(3, pp) == res_ok)											
			{
				x = 1;
			}

			Assert::AreEqual(x, 1);
			x = 0;

			Assert::AreEqual(p2.x, pp.x);
			Assert::AreEqual(p2.y, pp.y);
			Assert::AreEqual(p2.z, pp.z);

			if (test.get(9, pp) == res_ok)										
			{
				x = 1;
			}

			Assert::AreEqual(x, 1);
			x = 0;

			Assert::AreEqual(p3.x, pp.x);
			Assert::AreEqual(p3.y, pp.y);
			Assert::AreEqual(p3.z, pp.z);

			if (test.get(13, pp) == res_out_of_range)								
			{
				x = 1;
			}

			Assert::AreEqual(x, 1);
		}

		TEST_METHOD(test6_insert)
		{
			CList test;

			Assert::AreEqual((size_t)0, test.count);
			Assert::IsNull(test.first);

			point_t p, p2, p3;												

			p2.x = 4;
			p2.y = 8;
			p2.z = 3 + 2;
			test.insert(0, p2);

			Assert::IsNull(test.first->next);
			Assert::AreEqual(p2.x, test.first->p.x);
			Assert::AreEqual(p2.y, test.first->p.y);
			Assert::AreEqual(p2.z, test.first->p.z);
			Assert::AreEqual(test.count, (size_t)1);

			p.x = 24;																
			p.y = 84;
			p.z = 32 + 2;
			test.insert(0, p);

			list_el *second = test.first->next;

			Assert::AreEqual((size_t)2, test.count);
			Assert::AreEqual(test.first->p.x, p.x);
			Assert::AreEqual(test.first->p.y, p.y);
			Assert::AreEqual(test.first->p.z, p.z);

			Assert::IsNull(second->next);
			Assert::AreEqual(second->p.x, p2.x);
			Assert::AreEqual(second->p.y, p2.y);
			Assert::AreEqual(second->p.z, p2.z);

			p3.x = 2;																	
			p3.y = 4;
			p3.z = 2 + 23;
			test.insert(1, p3);

			list_el *second2 = test.first->next;
			list_el *third = second2->next;

			Assert::AreEqual((size_t)3, test.count);
			Assert::AreEqual(test.first->p.x, p.x);
			Assert::AreEqual(test.first->p.y, p.y);
			Assert::AreEqual(test.first->p.z, p.z);

			Assert::IsNull(third->next);
			Assert::AreEqual(second2->p.x, p3.x);
			Assert::AreEqual(second2->p.y, p3.y);
			Assert::AreEqual(second2->p.z, p3.z);

			Assert::AreEqual(third->p.x, p2.x);
			Assert::AreEqual(third->p.y, p2.y);
			Assert::AreEqual(third->p.z, p2.z);

			int x = 0;														

			p3.x = 29;
			p3.y = 45;
			p3.z = 23 + 23;

			if (test.insert(7, p3) == res_out_of_range)
			{
				x = 1;
			}

			Assert::AreEqual(1, x);
		}

		TEST_METHOD(test7_find)
		{
			CList test;

			size_t kr;

			point_t p, pp;

			int x = 0;														

			pp.x = 1;
			pp.y = 5;
			pp.z = 9;

			if (test.find(pp, kr) == res_error)
			{
				x = 1;
			}

			Assert::AreEqual(1, x);
			x = 0;

			test.push_back(pp);

			pp.x = 4;
			pp.y = 1;
			pp.z = 0;

			if (test.find(pp, kr) == res_out_of_range)						
			{
				x = 1;
			}

			Assert::AreEqual(1, x);
			x = 0;

			for (size_t i = 0; i <= 150; i++)					
			{
				p.x = i;
				p.y = 2 * i;
				p.z = 3 + i;
				test.push_back(p);
				if (i == 11)
				{
					pp = p;
				}
			}


			if (test.find(pp, kr) == res_ok)
			{
				x = 1;
			}

			Assert::AreEqual(1, x);

			Assert::AreEqual(kr, (size_t)12);
		}
	};
}