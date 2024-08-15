#ifndef RPN_HPP
# define RPN_HPP

class RPN {
    public:
        static void parser(const char *input);
    private:
        RPN(void);
        RPN(const RPN& src);
        RPN& operator=(const RPN& rhs);
        ~RPN(void);
};

#endif // !RPN_HPP
