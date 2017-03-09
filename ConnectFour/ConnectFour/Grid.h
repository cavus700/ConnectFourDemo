#pragma once

namespace grid {
	template < class T, size_t C, size_t R >
	class Grid
	{
	public:
		Grid();
		virtual ~Grid();

		virtual void newGame() = 0;
	
	protected:
		const std::vector<std::vector<T>>* m_grid;
	};

	template<class T, size_t C, size_t R>
	Grid<T, C, R>::Grid() : m_grid(new std::vector<std::vector<T>>(R, std::vector<T>(C)))
	{
	}

	template<class T, size_t C, size_t R>
	Grid<T, C, R>::~Grid()
	{
	}
}
