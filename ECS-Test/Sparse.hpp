/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Sparse.hpp
*/

#ifndef _SPARSE_HPP_
    #define _SPARSE_HPP_

    #include <vector>
    #include <memory>
    #include <optional>
    #include <iostream>

template <typename Component>
class Sparse_array {

    public:
        using value_type = std::optional<Component>;
        using reference_type = value_type&;
        using const_reference_type = value_type const&;
        using container_t = std::vector<value_type>;
        using size_type = typename container_t::size_type;
        using iterator = typename container_t::iterator;
        using const_iterator = typename container_t::const_iterator;

    public:
        /**
         * @brief Construct a new Sparse_array object
         */
        Sparse_array() = default;

        /**
         * @brief Construct a new Sparse_array object
         *
         * @param other Sparse_array to copy
         */
        Sparse_array(const Sparse_array& other)
        {
             for (std::size_t i = 0; i < other.size(); i++) {
                _data[i] = other._data[i];
            }
        };

        /**
         * @brief Construct a new Sparse_array object
         *
         * @param sp_arr Sparse_array to move
         */
        Sparse_array(Sparse_array &&sp_arr) noexcept
        {
            _data = std::move(sp_arr._data);
        }

        /**
         * @brief Destroy the Sparse_array object
         */
        ~Sparse_array() = default;


        /**
         * @brief Copy assignment operator
         *
         * @param sp_arr Sparse_array containing the operator to copy
         * @return Sparse_array& return adress of sparse arrays
         */
        Sparse_array &operator=(Sparse_array const &sp_arr)
        {
            std::swap(_data, sp_arr._data);
            return *this;
        };

        /**
         * @brief Move assignment operator
         *
         * @param sp_arr Sparse_array containing the operator to move
         * @return Sparse_array& return adress of sparse arrays
         */
         Sparse_array &operator=(Sparse_array &&sp_arr) noexcept
        {
            _data = std::move(sp_arr._data);
            return *this;
        };

        /**
         * @brief Access an element at the specified index.
         *
         * @param idx The index of the element to access.
         * @return reference_type A reference to the element at the specified index.
         */
        reference_type operator[](size_t idx)
        {
            return _data[idx];
        }

        /**
         * @brief Access an const element at the specified index.
         *
         * @param idx The index of the element to access.
         * @return const_reference_type A const reference to the element at the specified index.
         */
        const_reference_type operator[](size_t idx) const
        {
            return _data[idx];
        }

        /**
         * @brief Get the begin iterator
         *
         * @return iterator The first element iterator
         */
        iterator begin()
        {
            return _data.begin();
        }

        /**
         * @brief Get the begin iterator const
         *
         * @return const_iterator The first element iterator
         */
        const_iterator begin() const
        {
            return _data.begin();
        }

        /**
         * @brief Get the cbegin iterator const
         *
         * @return const_iterator The first element iterator
         */
        const_iterator cbegin() const
        {
            return _data.cbegin();
        }

        /**
         * @brief Get the end iterator
         *
         * @return iterator The last element iterator
         */
        iterator end()
        {
            return _data.end();
        }

        /**
         * @brief Get the end iterator const
         *
         * @return const_iterator The last element iterator
         */
        const_iterator end() const
        {
            return _data.end();
        }

        /**
         * @brief Get the cend iterator const
         *
         * @return const_iterator The last elemnen iterator
         */
        const_iterator cend() const
        {
            return _data.cend();
        }


        /**
         * @brief Get the size of _data
         *
         * @return size_type The size of the sparse array
         */
        size_type size() const
        {
            return _data.size();
        }

        /**
         * @brief Insert a lvalue at the specified position.
         *
         * @param pos The position at which to insert the lvalue.
         * @param value The lvalue to be inserted.
         * @return reference_type A reference to the inserted element.
         */
        reference_type insert_at(size_type pos, const Component &value)
        {
            if (pos > _data.size()) {
                _data.resize(pos + 1, Component{});
            }
            _data[pos] = value;
            return _data[pos];
        }

        /**
         * @brief Insert a rvalue at the specified position.
         *
         * @param pos The position at which to insert the rvalue.
         * @param value The rvalue to be inserted.
         * @return reference_type A reference to the inserted element.
         */
        reference_type insert_at(size_type pos, Component &&value)
        {
            if (pos > _data.size()) {
                _data.resize(pos + 1, Component{});
            }
            _data[pos] = std::move(value);
            return _data[pos];
        }

        template <class... Params>
        reference_type emplace_at(size_type pos, Params&&... params)
        {
            if (pos > _data.size()) {
                _data.resize(pos + 1);
            }
            std::allocator_traits<decltype(_data.get_allocator())>::destroy(
            _data.get_allocator(), std::addressof(_data[pos]));
            std::allocator_traits<decltype(_data.get_allocator())>::construct(
                _data.get_allocator(), std::addressof(_data[pos]), std::forward<Params>(params)...);
            return _data[pos];
        }

        /**
         * @brief Erase element of sparse array
         *
         * @param pos Index which should be erase
         */
        void erase(size_type pos)
        {
            _data[pos] = std::nullopt;
        }

        size_type get_index(const value_type& value) const
        {
            for (size_type i = 0; i < _data.size(); ++i) {
                if (_data[i] == value) {
                    return i;
                }
            }
            throw std::invalid_argument("Index out of range");
        }

    private:
        container_t _data;
};


#endif