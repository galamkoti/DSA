DECLARE
a number;
b boolean;
FUNCTION prime(n in number)
return boolean
IS
i number;
j numberj;
C NUMBER:=0;
BEGIN
FOR i IN 1..n loop1
    FOR j IN 1..i loop2
        IF MOD(I,J)=0 THEN
            C=C+1;
    end loop1;
end loop2;
IF C=2 THEN
    RETURN TRUE;
ELSE
    RETURN FALSE;
end;
BEGIN
a:=&a;
b:=prime(a);
dbms_output.put_line(b);
END;
/