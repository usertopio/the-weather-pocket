    // Header files
    // Child components
    #include "oledDisplay.h"

    // Component instances
    // Buttons
    ButtonNext buttonNext(2);
    ButtonConfirm buttonConfirm(3);

    // Constructor
    OledDisplay::OledDisplay(int oled_sda, int oled_scl,int screen_width, int screen_height, int address):   
        // Display configuration
        OLED_SDA(oled_sda),
        OLED_SCL(oled_scl),
        SCREEN_WIDTH(screen_width),
        SCREEN_HEIGHT(screen_height),
        ADDRESS(address),
        OLED_RESET(-1),
        // State
        state(State::WELCOME),
        // Libraries
        display(screen_width, screen_height, &Wire, OLED_RESET)
    {}

    // Initialization
    void OledDisplay::begin(){
        // Libraries
        Wire.begin(OLED_SDA, OLED_SCL);
        display.begin(SSD1306_SWITCHCAPVCC, ADDRESS);

        // State
        status = Status::ON;
    }

    // State
    OledDisplay::State OledDisplay::getState() const {
        return state;
    }

    void OledDisplay::setState(State newState) {
        state = newState;
    }

    void OledDisplay::updateDisplay(){
        buttonNext.readSignal();
        switch (getState())
        {
        case State::WELCOME:
            // Serial monitor
            Serial.println("Display: WELCOME");
            // Content
            display.clearDisplay();
            display.setTextSize(3);
            display.setTextColor(SSD1306_WHITE);
            display.setCursor(128, 64);
            display.print("WELCOME");
            display.display();
            // Check button next
            if (buttonNext.isButtonNextPressed())
            {
                setState(State::DISPLAY_WEATHER);
            }
            
            break;

        case State::DISPLAY_WEATHER:
            // Serial monitor
            Serial.println("Display: DISPLAY_WEATHER");
            // Content
            display.clearDisplay();
            display.setTextSize(3);
            display.setTextColor(SSD1306_WHITE);
            display.setCursor(128, 64);
            display.print("WELCOME");
            display.display();
            // Check button next
            if (buttonNext.isButtonNextPressed())
            {
                setState(State::DISPLAY_LOCATION);
            }
            break;

        case State::DISPLAY_LOCATION:
            // Serial monitor
            Serial.println("Display: DISPLAY_LOCATION");
            // Content
            display.clearDisplay();
            display.setTextSize(3);
            display.setTextColor(SSD1306_WHITE);
            display.setCursor(128, 64);
            display.print("WELCOME");
            display.display();
            // Check button next
            if (buttonNext.isButtonNextPressed())
            {
                setState(State::DISPLAY_SETTING);
            }
            break;
        
        case State::DISPLAY_SETTING:
            // Serial monitor
            Serial.println("Display: DISPLAY_SETTING");
            // Content
            display.clearDisplay();
            display.setTextSize(3);
            display.setTextColor(SSD1306_WHITE);
            display.setCursor(128, 64);
            display.print("WELCOME");
            display.display();
            // Check button next
            if (buttonNext.isButtonNextPressed())
            {
                setState(State::DISPLAY_WEATHER);
            }
            break;
        
        default:
            // Serial monitor
            Serial.println("Run out of oled display state!");
            setState(State::DISPLAY_WEATHER);
            break;
        }
    }