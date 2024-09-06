import sys

arguements = sys.argv

firstname = '';


if len(arguements) != 2:
    print("less arguements");

with open(arguements[1],'r') as file:
    for line in file:
        flag = 1;
        gender = '';
        degree = '';
        year = '';
        count = 0;
        line.strip();
        for char in line:
            if(count == 4 and char != "\n"):
                degree += char;
            if char == ',':
                count += 1;
        count = 0;
        for char in line:
            if(count == 2 and char != ','):
                gender += char;
            if char == ',':
                count += 1;
        count = 0;
        for char in line:
            if(count == 3 and char != ','):
                year += char;
            if char == ',':
                count += 1;
        count = 0;
        #print(degree+"-"+year+"-"+gender+"\n");
        if degree == 'Msc' and  year == '2024' and gender == 'F':
            for char in line:
                if(count == 1 and flag == 1):
                    firstname += char;
                if char == ',':
                    count += 1;
                if(char == ' '):
                    flag = 0;
    print(firstname+"\n");
file.close();
