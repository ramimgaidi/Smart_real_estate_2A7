<?php

namespace App\Controller;

use App\Entity\Club;
use App\Form\ClubType;
use App\Repository\ClubRepository;
use Doctrine\Persistence\ManagerRegistry;
use Symfony\Bundle\FrameworkBundle\Controller\AbstractController;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\HttpFoundation\Response;
use Symfony\Component\Routing\Annotation\Route;


class ClubController extends AbstractController
{
    #[Route('/clubs', name: 'listeclub')]
    public function liste(ManagerRegistry $mg): Response
    {
    $repo=$mg->getRepository(Club::class);
    $result=$repo->findAll();
        return $this->render('club/index.html.twig', [
            'clubs' => $result,
        ]);
    }

    #[Route('/addclub', name: 'addclub')]
    public function addClub(Request $request, ManagerRegistry $mg): Response
    {
        $club = new Club();
        $form = $this->createForm(ClubType::class, $club);
        $form->handleRequest($request);
        if ($form->isSubmitted() ) {
        $em=$mg->getManager();
        $em->persist($club);
            return $this->redirectToRoute('listeclub');
        }

        return $this->render('club/new.html.twig', [
            'form' => $form->createView(),
        ]);
    }

    #[Route('/detail/{id}', name: 'detail')]
    public function deailClub($id,ClubRepository $repo): Response
    {
        $result=$repo->find($id);
        return $this->render('club/show.html.twig', [
            'club' => $result,
        ]);
    }

    #[Route('/update/{id}', name: 'update')]
    public function updateClub(Request $request, $id, ClubRepository $repo,
    ManagerRegistry $mg
    ): Response
    {$club=$repo->find($id);
        $form = $this->createForm(ClubType::class, $club);
        $form->handleRequest($request);

        if ($form->isSubmitted() ) {
         $em=$mg->getManager();
         $em->persist($club); 
         $em->flush();
            return $this->redirectToRoute('listeclub');
        }

        return $this->renderForm('club/edit.html.twig', [
            'form' => $form,
        ]);
    }

    #[Route('/removeclub/{id}', name: 'removeclub')]
    public function deleteClub($id, ClubRepository $repo,ManagerRegistry $mg): Response
    {
        $em=$mg->getManager();
            $result=$repo->find($id);
            $em->remove($result);
            $em->flush();

        return $this->redirectToRoute('listeclub');
    }
}
