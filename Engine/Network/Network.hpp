/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Network
*/

#ifndef NETWORK_HPP_
    #define NETWORK_HPP_

    #include <string>
    #include <vector>

    class IReceiver {
    /**
     * @brief Virtual receive class
    */
    public:
        virtual ~IReceiver() = default;

        virtual void receive() = 0;
        virtual std::vector<std::string> GetReceivedData() = 0;
        virtual void ClearReceivedData() = 0;
        virtual void ClearReceivedDataAtIndex(int index) = 0;
        virtual void ClearLastReceivedData() = 0;
        virtual void ClearFirstReceivedData() = 0;
        virtual bool IsPortBound() = 0;
    };

    class ISender {
    /**
     * @brief Virtual send class
    */
    public:
        virtual ~ISender() = default;
        virtual void send(std::string in) = 0;
        virtual void send(std::vector<std::string> in) = 0;
        virtual int get_port() = 0;
        virtual std::string get_ip() = 0;
    };

#endif /* !NETWORK_HPP_ */
