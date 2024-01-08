/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Registry.hpp
*/

#ifndef REGISTRY_HPP_
    #define REGISTRY_HPP_

    #include <map>
    #include <unordered_map>
    #include <any>
    #include <typeindex>
    #include <functional>
    #include <string>
    #include <iostream>
    #include <complex>

    #include "Sparse.hpp"
    #include "Entity.hpp"

class Registry
{
    public:
        explicit Registry() = default;
        virtual ~Registry() = default;


        template <class Component>
        Sparse_array<Component> &register_component()
        {
            auto& componentArray = _componentsArrays[typeid(Component)];

            if (componentArray.has_value() == false) {
                componentArray = Sparse_array<Component>();
            }

            return std::any_cast<Sparse_array<Component>&>(componentArray);
        };

        template <class Component>
        Sparse_array<Component> &get_components()
        {
            auto it = _componentsArrays.find(std::type_index(typeid(Component)));

            if (it == _componentsArrays.end()) {
                throw std::out_of_range("Component not registered in the registry");
            }
            return std::any_cast<Sparse_array<Component> &>(it->second);
        }

        template <class Component>
        Sparse_array<Component> const &get_components() const
        {
            auto it = _componentsArrays.find(std::type_index(typeid(Component)));

            if (it == _componentsArrays.end()) {
                throw std::out_of_range("Component not registered in the registry");
            }
            return std::any_cast<Sparse_array<Component> &>(it->second);
        };

        Entity spawn_entity()
        {
            _nbEntities += 1;

            return Entity(_nbEntities - 1);
        };

         Entity entity_from_index(std::size_t idx) const
        {
            if (idx >= _nbEntities) {
                throw std::out_of_range("Entity doesn't exist");
            }
            return Entity(idx);
        };

        void kill_entity(Entity const &e)
        {
            for (auto &&it : _erasers)
                it(*this, e);
        };

        template <typename Component>
        typename Sparse_array<Component>::reference_type add_component(Entity const &e, Component &&c)
        {
            if (_componentsArrays.find(std::type_index(typeid(Component))) == _componentsArrays.end())
                throw std::invalid_argument("Component already exists");
            try {
                Sparse_array<Component> &sparseArray = std::any_cast<Sparse_array<Component> &>(_componentsArrays.at(std::type_index(typeid(Component))));

                if (e > sparseArray.size()) {
                    sparseArray.extend((size_t) e - sparseArray.size());
                }
                return sparseArray.insert_at(e, c);
            } catch (const std::bad_any_cast &e) {
                throw std::invalid_argument("Error");
            }
        };

        template <typename Component, typename ...Params>
        typename Sparse_array<Component>::reference_type emplace_component(Entity const &to, Params &&...p)
        {
            Sparse_array<Component> sparseArray = std::any_cast<Sparse_array<Component> &>(_componentsArrays.at(std::type_index(typeid(Component))));
            return sparseArray.emplaceAt(to, p...);
        };

        template <typename Component>
        void remove_component(Entity const &from)
        {
            Sparse_array<Component> &sparseArray = std::any_cast<Sparse_array<Component> &>(_componentsArrays.at(std::type_index(typeid(Component))));

            if (sparseArray.size() > from) {
                sparseArray.erase(from);
            }
        };

    private:
        std::unordered_map<std::type_index, std::any> _componentsArrays;
        std::size_t _nbEntities = 0;
        std::vector<std::function<void (Registry &, Entity const &)>> _erasers;

        template <class Component>
        bool is_registered() const {
            return _componentsArrays.find(typeid(Component)) != _componentsArrays.end();
        }
};

#endif