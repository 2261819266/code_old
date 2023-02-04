#include <cstdio>
#include <vector>
#include <stack>


struct RegularExpression {
	using value_type = double;

	using operator_type = value_type(*)(const value_type &x, const value_type &y);
	
	operator_type addition = [](const value_type &x, const value_type &y) -> value_type { return x + y; };
	operator_type substraction = [](const value_type &x, const value_type &y) -> value_type { return x - y; };
	operator_type multiplication = [](const value_type &x, const value_type &y) -> value_type { return x * y; };
	operator_type division = [](const value_type &x, const value_type &y) -> value_type { return x / y; };

	struct ValOrOpt {
		void *p;
		value_type x;
		operator_type f;
		
		ValOrOpt() {
			p = 0;
			x = 0;
			f = 0;
		}

		template<typename t> ValOrOpt(const t &val) {
			*this = val;
		}

		void operator=(const value_type &value) {
			x = value;
			p = &x;
			f = 0;
		}
		void operator=(const operator_type &opt) {
			f = opt;
			p = &f;
		}

		bool isValue() const {
			return *(value_type*)p == x;
		}

		bool isOperator() const {
			return *(operator_type*)p == f;
		}

		operator value_type() { return x; }
		operator operator_type() { return f; }
	};

	std::vector<ValOrOpt> a;

	template<typename t> void push(const t &x) {
		a.push_back((ValOrOpt)(x));
	}

	value_type calculation() {
		std::stack<value_type> s;

		// if (a.front().isOperator()) return 0;

		for (ValOrOpt i : a) {
			if (i.isValue()) s.push(i);
			else if (i.isOperator()) {
				if (s.size() < 2) return 0;
				value_type first, second;
				second = s.top();
				s.pop();
				first = s.top();
				s.pop();
				operator_type f = i;
				s.push(f(first, second));
			} else return 0;
		}
		return s.top();
	}
};

// int main() {
// 	RegularExpression a;
// 	a.a = {6, 1, 6, 8, a.division, a.substraction, a.division};
// 	printf("%lf", a.calculation());
// }