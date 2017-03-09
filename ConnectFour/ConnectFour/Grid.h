#pragma once

namespace grid {
	template < typename T, size_t C, size_t R >
	class Grid
	{
	public:
		Grid();
		virtual ~Grid();

		virtual void newGame() = 0;
	
	protected:
		std::vector<std::vector<T>> m_grid;
	};

	template<typename T, size_t C, size_t R>
	Grid<T, C, R>::Grid() : m_grid(std::vector<std::vector<T>>(R, std::vector<T>(C)))
	{
	}

	template<typename T, size_t C, size_t R>
	Grid<T, C, R>::~Grid()
	{
	}
}
