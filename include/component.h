#ifndef Component_H
#define Component_H

class Component {
    public:
        // Constructor
        Component();
        virtual ~Component() = default;

        // Status
        enum class Status {
            ON,
            OFF
        };

        //  Initialization
        virtual void begin() = 0;

        // Status
        Status getStatus() const;
        Status toggleStatus();
        const char* statusToStr(Status status) const;

    protected:
        // Status
        Status status;
};

#endif