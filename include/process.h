#ifndef PROCESS_H
#define PROCESS_H

class Process {
    // Constructor
    public:
        // Methods
        Process();

    // Initialization
    public:
        // Methods
        void begin();

    // State
    protected:
        // Variables
        enum class State {
            INIT,
            MEASURE,
            DATA
        };
  
        State state;

    public:
        // Methods
        State getState() const;
};

#endif