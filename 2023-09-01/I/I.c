#include <stdio.h>

int main () {
    int ncases;
    scanf("%d", &ncases);
    for (int i = 1; i <= ncases; i++) {
        int ndoors;
        double success_prob = 0.0;
        double expected_step = 0.0;
        scanf("%d", &ndoors);
        while (ndoors--) {
            int time;
            double prob;
            scanf("%d %lf", &time, &prob);
            if (time < 0) time = -time;
            else success_prob += prob;
            expected_step += time*prob;
        }
        printf("Case %d: ", i);
        if (success_prob == 0.0) printf("God! Save me\n");
        else printf("%.2lf\n", expected_step/success_prob);
    }
    return 0;
}
