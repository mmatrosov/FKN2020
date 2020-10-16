class NotifierBase {
protected:
    std::string type;
    std::string address;

public:
    void Notify(const std::string& text) const {
        if (type == "email")
            SendEmail(address, text);
        if (type == "sms")
            SendSms(address, text);
    }

    virtual ~NotifierBase() {
    }
};

class SmsNotifier : public NotifierBase {
public:
    SmsNotifier(const std::string& address0) {
        address = address0;
        type = "sms";
    }

    ~SmsNotifier() {
    }
};

class EmailNotifier : public NotifierBase {
public:
    EmailNotifier(const std::string& address0) {
        address = address0;
        type = "email";
    }

    ~EmailNotifier() {
    }
};